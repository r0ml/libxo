// swift-tools-version: 6.0
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "libxo",
    products: [
        // Products define the executables and libraries a package produces, making them visible to other packages.
        .library(
            name: "xo",
            type: .static,
            targets: ["libxo"]),
    ],
    targets: [
        // Targets are the basic building blocks of a package, defining a module or a test suite.
        // Targets can depend on other targets in this package and products from dependencies.
        .target(
          name: "libxo",
          cSettings: [.define("XO_SHAREDIR=\"/usr/local/share/libxo\""),
                      .define("XO_ENCODERDIR=\"/usr/lib/libxo/encoder\"")]
            
        ),
        .testTarget(
            name: "libxoTests",
            dependencies: ["libxo"]
        ),
    ]
)
