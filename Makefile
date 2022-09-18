IMAGE = tic-tac-toe-ai
DOCKER = docker run --rm -v "$(PWD)":/app

.PHONY: build-docker-image
build-docker-image:
	@docker build -t $(IMAGE) - < Dockerfile

.PHONY: build
build: build-docker-image
	@$(DOCKER) $(IMAGE) bash -c "cmake -B build && cmake --build build"

.PHONY: test
test: build
	@$(DOCKER) -w /app/build $(IMAGE) ctest

.PHONY: run
run:
	@if [[ "$$(docker images -q $(IMAGE) 2>/dev/null)" == "" ]]; then \
	  echo "Building Docker image..."; \
	  make build-docker-image 2>/dev/null; \
	fi
	@if ! [[ -x build/ttt ]]; then \
	  echo "Compiling source..."; \
	  make build >/dev/null 2>&1; \
	fi
	@$(DOCKER) -it $(IMAGE) build/ttt

.PHONY: shell
shell: build-docker-image
	@$(DOCKER) -it $(IMAGE) bash
