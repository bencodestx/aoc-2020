FROM ubuntu:21.04

ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update \
      && apt-get upgrade -y \
      && apt-get install -y \
        clang-10 \
        cmake \
      && rm -rf /var/lib/apt/lists/*
