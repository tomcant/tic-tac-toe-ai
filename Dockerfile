FROM gcc:12.2

RUN apt update \
 && apt install -y cmake clang-format \
 && rm -rf /var/lib/apt/lists/*

WORKDIR /app
