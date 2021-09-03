#! /bin/sh

# Build without root privilig, in order to use the user rust toolchain
echo "> Build binaries"
cargo build --release --manifest-path ../Cargo.toml

echo "> Copie binaries into system path (/usr/local/bin), root privileges required"
sudo cp ../target/release/rumno /usr/local/bin
sudo cp ../target/release/rumno-background /usr/local/bin
