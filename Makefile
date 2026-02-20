# StratoLab Development Makefile
#
# Provides convenient shortcuts for local development.
# Requires: Python 3 (for local server and validation)
# Note: serve and open targets delegate to ./serve.sh
#
# Usage:
#   make          Show this help
#   make serve    Start local dev server
#   make open     Start server and open browser
#   make validate Check that site-config.json is valid JSON
#   make check    Run all validations
#
# Override the default port:
#   make serve PORT=3000
#   make open  PORT=3000

PORT ?= 8000

.PHONY: help serve open validate check

## help: Show available make targets (default)
help:
	@echo ""
	@echo "StratoLab - Available commands:"
	@echo ""
	@grep -E '^## [a-zA-Z_-]+:' $(MAKEFILE_LIST) \
		| sed 's/^## /  make /' \
		| sed 's/:/ - /'
	@echo ""
	@echo "Override the default port: make serve PORT=3000"
	@echo ""

## serve: Start local dev server at http://localhost:$(PORT)
serve:
	./serve.sh -p $(PORT)

## open: Start local dev server and open in default browser
open:
	./serve.sh -o -p $(PORT)

## validate: Validate that site-config.json is valid JSON
validate:
	@echo "Checking site-config.json..."
	@python3 -c "import json; json.load(open('site-config.json')); print('  site-config.json: OK')"

## check: Run all validations
check: validate
	@echo ""
	@echo "All checks passed."
	@echo ""
