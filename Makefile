IMAGE_NAME := code-cpp
CONTAINER_NAME := code-cpp

# Mapea el repo local -> /config/workspace (persisten tus archivos)
WORKDIR := $(shell pwd)

# Puerto host donde abrirás VS Code en el navegador
HOST_PORT := 8080

# Credenciales y zona horaria para code-server (puedes sobreescribir por CLI)
PASSWORD ?= changeme
TZ ?= America/Guatemala

# Usa tu UID/GID para evitar permisos raros en los archivos montados
PUID ?= $(shell id -u)
PGID ?= $(shell id -g)


CONFIG_DIR := $(WORKDIR)/.code_config

.PHONY: build run stop rm logs sh

banner: 
	bash banner_ecfm.sh

docker-build: banner
	docker build -t $(IMAGE_NAME) .

docker-run:
	@mkdir -p $(CONFIG_DIR)
	@echo "Abre: http://localhost:$(HOST_PORT) (password: $(PASSWORD))"
	docker run -d --name $(CONTAINER_NAME) \
		-e PUID=$(PUID) -e PGID=$(PGID) \
		-e TZ=$(TZ) \
		-e PASSWORD=$(PASSWORD) \
		-p $(HOST_PORT):8443 \
		-v "$(CONFIG_DIR)":/config \
		-v "$(WORKDIR)":/config/workspace \
		$(IMAGE_NAME)

docker-build-run: docker-build docker-run

docker-start:
	docker start $(CONTAINER_NAME) || true

docker-stop:
	docker stop $(CONTAINER_NAME) || true

docker-rm: stop
	docker rm $(CONTAINER_NAME) || true

docker-sh:
	docker exec -it $(CONTAINER_NAME) bash