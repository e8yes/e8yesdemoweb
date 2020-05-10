FROM ubuntu:20.04

# Install required packages.
WORKDIR /home/demoweb_src
ENV DEBIAN_FRONTEND=noninteractive
RUN apt update
RUN apt install -y build-essential
RUN echo 13 | apt install -y postgresql
RUN apt install -y libpqxx-dev
RUN apt install -y libprotobuf-dev
RUN apt install -y protobuf-compiler
RUN apt install -y libgrpc++-dev
RUN apt install -y libcrypto++-dev
RUN apt install -y qt5-default

# Copy source code.
WORKDIR /home

RUN mkdir -p demoweb_src
ADD . /home/demoweb_src
RUN ls -lh

# Build project.
WORKDIR /home
RUN mkdir -p build
WORKDIR /home/build
RUN qmake ../demoweb_src/e8.pro
RUN make -j `nproc --all`