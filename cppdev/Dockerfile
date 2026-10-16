FROM ubuntu:26.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y \
        build-essential \
        cmake \
        clang \
        libssl-dev \
        vim \
    && \
    rm -rf /var/lib/apt/lists/*