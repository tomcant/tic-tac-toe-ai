FROM gcc:12.2

RUN apt update \
 && apt install -y cmake \
 && rm -rf /var/lib/apt/lists/*

WORKDIR /app
