# Signature Test Example

Demonstrates using a hash digest to sign and verify a signature using Ed448

First, set the path to wolfssl directory to variable WOLFROOT in the Makefile.
## Building

### Build example

```
make
```

## Usage

```
./ed448_sign_verify
Verified!
```


# Signature verification Benchmark

You can generate benchmark program .
```
make bench
```

## Example Output
```
./ed448_sign_verify_bench
Running Benchmark for Ed448...
Please wait 1.0 seconds,
  2127.21 Cycles/sec
Finished Benchmark!
```

# Tracking memory
To see a stack and heap memory usage.

```
make mem
```
## Example Output
```
./ed448_sign_verify_mem
Verified!
[Memory Usage]
total   Allocs   =         1
total   Deallocs =         1
total   Bytes    =       136
peak    Bytes    =       136
current Bytes    =         0
stack used = 7504

```


Best wishes in all your testing!

- The wolfSSL Team
