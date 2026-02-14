#!/bin/bash
# StratoLab Local Development Server
#
# Starts a simple HTTP server to preview the site locally.
# The dynamic website requires a web server - opening index.html
# directly in a browser will not work.
#
# Usage: ./serve.sh [-o] [-p PORT]
#   -o        Open browser after starting server
#   -p PORT   Specify port (default: 8000)
#
# Examples:
#   ./serve.sh           # Start server at http://localhost:8000
#   ./serve.sh -o        # Start server and open browser
#   ./serve.sh -p 3000   # Use port 3000

set -e

PORT=8000
OPEN_BROWSER=false

# Parse command line arguments
while getopts "op:" opt; do
  case $opt in
    o) OPEN_BROWSER=true ;;
    p) PORT="$OPTARG" ;;
    \?)
      echo "Usage: $0 [-o] [-p PORT]"
      exit 1
      ;;
  esac
done

# Check if port is already in use
check_port() {
  if command -v lsof &> /dev/null; then
    if lsof -i:"$PORT" &> /dev/null; then
      return 0  # Port is in use
    fi
  elif command -v ss &> /dev/null; then
    if ss -tuln | grep -q ":$PORT "; then
      return 0  # Port is in use
    fi
  elif command -v netstat &> /dev/null; then
    if netstat -tuln 2>/dev/null | grep -q ":$PORT "; then
      return 0  # Port is in use
    fi
  fi
  return 1  # Port is available (or we couldn't check)
}

if check_port; then
  echo "Error: Port $PORT is already in use."
  echo ""
  echo "Options:"
  echo "  1. Stop the other program using port $PORT"
  echo "  2. Use a different port: $0 -p 3001"
  exit 1
fi

echo "=========================================="
echo "  StratoLab Local Development Server"
echo "=========================================="
echo ""
echo "  Site URL:  http://localhost:$PORT"
echo "  Stop:      Press Ctrl+C"
echo ""
echo "=========================================="
echo ""

# Open browser if requested (do this before starting server)
if [ "$OPEN_BROWSER" = true ]; then
  (
    # Small delay to let server start
    sleep 1
    if [[ "$OSTYPE" == "darwin"* ]]; then
      open "http://localhost:$PORT"
    elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
      xdg-open "http://localhost:$PORT" 2>/dev/null || true
    elif [[ "$OSTYPE" == "msys" ]] || [[ "$OSTYPE" == "cygwin" ]]; then
      start "http://localhost:$PORT" 2>/dev/null || true
    fi
  ) &
fi

# Start the HTTP server
if command -v python3 &> /dev/null; then
  python3 -m http.server "$PORT"
elif command -v python &> /dev/null; then
  # Check if this is Python 2 or 3
  PY_VERSION=$(python -c 'import sys; print(sys.version_info[0])')
  if [ "$PY_VERSION" = "3" ]; then
    python -m http.server "$PORT"
  else
    python -m SimpleHTTPServer "$PORT"
  fi
else
  echo "Error: Python not found."
  echo ""
  echo "Please install Python 3:"
  echo "  - macOS:  brew install python3  (or use built-in python3)"
  echo "  - Ubuntu: sudo apt install python3"
  echo "  - Other:  https://www.python.org/downloads/"
  echo ""
  echo "Alternatively, if you have Node.js installed:"
  echo "  npx serve -p $PORT"
  echo "  npx http-server -p $PORT"
  exit 1
fi
