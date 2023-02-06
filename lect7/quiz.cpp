#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/ssl.hpp>
#include <boost/beast/version.hpp>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

namespace asio = boost::asio;
namespace beast = boost::beast;

int main() {
    try {
        const char *const host = "weather.com";
        const char *const port = "443";
        const char *const target = "/ko-KR/weather/today/l/4e73be5bb1986d9da1aea69b87c0c9992ad65aecd6fa642d1307f8c488fb6803";
        int version = 11;

        // The io_context is required for all I/O
        asio::io_context ioc;

        // The SSL context is required, and holds certificates
        asio::ssl::context ctx(asio::ssl::context::tls_client);

        // Verify the remote server's certificate
        ctx.set_verify_mode(asio::ssl::verify_none);

        // These objects perform our I/O
        asio::ip::tcp::resolver resolver(ioc);
        beast::ssl_stream<beast::tcp_stream> stream(ioc, ctx);

        // Set SNI Hostname (many hosts need this to handshake successfully)
        if (!SSL_set_tlsext_host_name(stream.native_handle(), host)) {
            beast::error_code ec{ static_cast<int>(::ERR_get_error()), asio::error::get_ssl_category() };
            throw beast::system_error{ ec };
        }

        // Look up the domain name
        const auto results = resolver.resolve(host, port);

        // Make the connection on the IP address we get from a lookup
        beast::get_lowest_layer(stream).connect(results);

        // Perform the SSL handshake
        stream.handshake(asio::ssl::stream_base::client);

        // Set up an HTTP GET request message
        beast::http::request<beast::http::string_body> req{ beast::http::verb::get, target, version };
        req.set(beast::http::field::host, host);

        // Send the HTTP request to the remote host
        beast::http::write(stream, req);

        // This buffer is used for reading and must be persisted
        beast::flat_buffer buffer;

        // Receive the HTTP response
        beast::http::response<beast::http::string_body> res;
        beast::http::read(stream, buffer, res);

        // Write the message to standard out
        auto body = res.body();

        // Print response body
        for (int i = 0; i < body.size(); i += 1000) {
            // std::cout << body.substr(i, 1000) << std::endl; // becouse of large content
        }

        body = body.substr(body.find("<span data-testid=\"TemperatureValue\" class=\"CurrentConditions--tempValue--MHmYY\">") + 81);
        body = body.substr(0, body.find("</span>") - 1);
        std::cout << "Seoul Temperature: " << body << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
