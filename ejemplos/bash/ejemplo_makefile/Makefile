WORKDIR := $(shell pwd)
CONFIG_DIR := $(WORKDIR)/.code_config

banner: 
	bash banner_ecfm.sh

ejecutar-pipeline: banner
	python3 ../ejemplo_python/limpiar.py
	python3 ../ejemplo_python/analizar.py
	python3 ../ejemplo_python/graficar.py

deploy: banner tests
	@echo "Inicia despliege del codigo...."
	mkdir -p $(CONFIG_DIR) 

deploy_run: deploy ejecutar-pipeline

tests:
	@echo "Pruebas unitarias...."