# Signature Test Example

Demonstrates using a hash digest to sign and verify a signature using Ed25519

First, set the path to wolfssl directory to variable WOLFROOT in the Makefile.
## Building

### Build example

```
make
```

## Usage

```
./ed25519_sign_verify
verified!
```

  

# Build Options

You can generate program with some options.
## To generate Architecture specific code

If you build for x86_64 system:
```
make arch=x64
```
else if Aarch64 system: 
```
make arch=arm64
``` 
then an archtecture specialized program is generated.

## To generate Low Memory performance code

```
make mem=low
```


# Example Output
- built with the option `
arch=arm64`
```
 ./ed25519_sign_verify_bench
Running Benchmark for Ed25519...
Please wait 1.0 seconds,
17769.84 Cycles/sec
Finished Benchmark!
```

## Tracking memory
To see the stack and heap memory usage.

```
make mem
```

- build with the option `mem=low`
```
./ed25519_sign_verify_mem
Verified!
 [Memory Usage]
total   Allocs   =         1
total   Deallocs =         1
total   Bytes    =       136
peak    Bytes    =       136
current Bytes    =         0
stack used = 3295
```


Best wishes in all your testing!

- The wolfSSL Team
