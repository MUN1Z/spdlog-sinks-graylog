
# spdlog-sinks-graylog

A custom sink for the [spdlog](https://github.com/gabime/spdlog) logging library that sends log messages to [Graylog](https://www.graylog.org) using GELF (Graylog Extended Log Format) over UDP or TCP.

## Features

- Sends logs from `spdlog` to Graylog.
- Supports both UDP and TCP protocols.
- Customizable log levels and configuration options.
- Uses:
  - [Asio](https://think-async.com) for network communication.
  - [nlohmann-json](https://github.com/nlohmann/json) for JSON message serialization.
  - [spdlog](https://github.com/gabime/spdlog) for integration with existing logging infrastructure.

## Installation

### Prerequisites

Ensure you have the following dependencies installed:
- A C++17 or later compiler.
- CMake 3.15 or higher.
- vcpkg (optional) for managing dependencies.

### Building the Project

#### Using vcpkg

1. Clone the repository:
   ```bash
   git clone https://github.com/MUN1Z/spdlog-sinks-graylog.git
   cd spdlog-sinks-graylog
   ```

2. Install dependencies using `vcpkg`:
   ```bash
   vcpkg install asio nlohmann-json spdlog
   ```

3. Build the project:
   ```bash
   mkdir build && cd build
   cmake .. -DCMAKE_TOOLCHAIN_FILE=<path-to-vcpkg>/scripts/buildsystems/vcpkg.cmake
   make
   ```

#### Without vcpkg

Manually download and integrate the dependencies into your project:
- [Asio](https://think-async.com)
- [nlohmann-json](https://github.com/nlohmann/json)
- [spdlog](https://github.com/gabime/spdlog)

Update your CMakeLists.txt to include the paths to these libraries.

## Usage

### Example: Basic Integration

Here’s an example of how to use the custom Graylog sink with `spdlog`:

```cpp
#include "gray_log_sink.hpp"

int main() {
    // Configure Graylog sink options
    GrayLogSinkOptions options{
        "127.0.0.1",      // Graylog host
        "MyApp",          // Source application name
        "info"            // Log level
        12201,            // Port (default for GELF)
    };

    // Create Graylog sink
    auto graylog_sink = std::make_shared<GrayLogSink>(options);

    // Create a logger with the custom sink
    auto logger = std::make_shared<spdlog::logger>("graylog_logger", graylog_sink);

    // Log messages
    logger->info("This is an info message sent to Graylog.");
    logger->error("This is an error message sent to Graylog.");
}
```

### Configuration

#### Options in `GrayLogSinkOptions`

| Field                | Description                           | Example               |
|----------------------|---------------------------------------|-----------------------|
| `hostNameOrAddress`  | Graylog server address or hostname    | `"127.0.0.1"`         |
| `source`             | Source name to identify the sender   | `"MyApp"`             |
| `level`              | Minimum log level to send to Graylog | `info`                |
| `port`               | Port for GELF communication          | `12201`               |
#### Protocol Configuration
By default, the sink uses UDP. To enable TCP, adjust the `GrayLogSink` implementation to create a TCP socket.

## Contributing

1. Fork the repository.
2. Create your feature branch (`git checkout -b feature/my-feature`).
3. Commit your changes (`git commit -m 'Add my feature'`).
4. Push to the branch (`git push origin feature/my-feature`).
5. Open a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

## Acknowledgments

- [spdlog](https://github.com/gabime/spdlog) for the logging framework.
- [Graylog](https://www.graylog.org) for the centralized logging platform.
- [nlohmann-json](https://github.com/nlohmann/json) for JSON serialization.
- [Asio](https://think-async.com) for networking utilities.

---

Feel free to reach out if you have any issues or suggestions!
