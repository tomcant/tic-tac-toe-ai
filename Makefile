IMAGE = tic-tac-toe-ai
DOCKER = docker run --rm -v "$(PWD)":/app

##@ Play

.PHONY: play
play: ## Play Tic-tac-toe against the AI
	@if [[ "$$(docker images -q $(IMAGE) 2>/dev/null)" == "" ]]; then \
	  make build-docker-image; \
	fi
	@if ! [[ -x build/ttt ]]; then \
	  make build; \
	fi
	@printf "\n"
	@$(DOCKER) -it $(IMAGE) build/ttt

##@ Develop

.PHONY: test
test: build ## Run the test suite
	@$(DOCKER) -w /app/build $(IMAGE) ctest

.PHONY: format
format: build-docker-image ## Format the source code
	@$(DOCKER) $(IMAGE) clang-format -i src/* tests/*

.PHONY: check-format
check-format: build-docker-image
	@$(DOCKER) $(IMAGE) clang-format --dry-run --Werror src/* tests/*

.PHONY: build
build: build-docker-image ## Build a binary from the source code
	@$(DOCKER) $(IMAGE) bash -c "cmake -B build && cmake --build build"

.PHONY: shell
shell: build-docker-image ## Enter an interactive shell with GCC and CMake
	@$(DOCKER) -it $(IMAGE) bash

.PHONY: build-docker-image
build-docker-image:
	@docker build -t $(IMAGE) - < Dockerfile

.DEFAULT_GOAL := help
.PHONY: help
help:
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make \033[36m<target>\033[0m\n"} /^[a-zA-Z\%\/_-]+:.*?##/ { printf "  \033[36m%-10s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)
