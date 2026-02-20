# Contributing to StratoLab Documentation

Welcome! This repository contains educational documentation for the StratoLab high-altitude balloon project. Contributions from students, teachers, mentors, and community members are encouraged.

## Quick Start

1. Read the [Git Workflow Guidelines](.prompts/git-workflow.md)
2. Review the [Documentation Standards](.prompts/documentation-standards.md)
3. Fork the repository and create a branch using the naming conventions in the git workflow guide
4. Make your changes following the guidelines
5. **Test locally** using the instructions below
6. Submit a pull request — a [template](.github/PULL_REQUEST_TEMPLATE.md) will guide you through the checklist

## Local Development

Before pushing changes to GitHub, test your edits locally to make sure everything
displays correctly. The site uses JavaScript to load content dynamically, so you
need a local web server — opening `index.html` directly in your browser will not work.

### Prerequisites

**Python 3** is required (pre-installed on most macOS and Linux systems).

Check if you have it:
```bash
python3 --version
```

If not installed, download from [python.org/downloads](https://www.python.org/downloads/).

### Starting the Local Server

**Using Make (recommended for macOS/Linux):**

```bash
make serve
```

Then open your browser to [http://localhost:8000](http://localhost:8000)

**Make options:**
- `make open` — Start server and open browser automatically
- `make serve PORT=3000` — Use a different port

**Using the helper script directly (alternative):**

The `make` targets delegate to `./serve.sh`. You can also run it directly:

```bash
./serve.sh
```

Script options: `./serve.sh -o` (open browser), `./serve.sh -p 3000` (custom port)

**Manual method (Windows or if script doesn't work):**

```bash
# Python 3
python3 -m http.server 8000

# Or on Windows
python -m http.server 8000
```

**Alternative using Node.js (if you have it installed):**

```bash
npx serve -p 8000
# or
npx http-server -p 8000
```

### Stopping the Server

Press `Ctrl+C` in the terminal where the server is running.

### Troubleshooting

**"Address already in use" error:**

Another program is using port 8000. Either stop that program, or use a
different port: `make serve PORT=3001` or `./serve.sh -p 3001`

**Changes not appearing:**

Hard refresh your browser:
- Windows/Linux: `Ctrl+Shift+R`
- macOS: `Cmd+Shift+R`

**"Python not found" error:**

Install Python 3 from [python.org/downloads](https://www.python.org/downloads/)

**"Permission denied" when running serve.sh:**

Make the script executable: `chmod +x serve.sh`

## Makefile Reference

Run `make` with no arguments to see all available commands:

```bash
make
```

| Command | Description |
|---|---|
| `make serve` | Start the local server at http://localhost:8000 |
| `make open` | Start the server and open a browser tab automatically |
| `make validate` | Check that `site-config.json` is valid JSON |
| `make check` | Run all available validations |

You can override the default port for any server command:

```bash
make serve PORT=3000
make open PORT=3000
```

**Note for Windows users:** `make` is not installed by default on Windows. Use the helper script or manual Python method below instead.

## What Goes Here

- Lesson content and tutorials
- Hardware assembly guides
- Research documentation
- Materials lists and checklists
- Educational resources

## What Goes Elsewhere

- **Code**: Arduino, MicroPython, and ESP32 code lives in the separate telemetry code repository
- **Issues**: If you find a problem, open an issue before starting work so the team is aware

## Safety

This is not typical documentation. Errors in wiring diagrams, specifications, or procedures can have real-world consequences. If your changes touch anything hardware-related, include a `SAFETY:` note in your commit message. See the [Git Workflow Guidelines](.prompts/git-workflow.md) for details.

## Getting Help

- Ask your mentor or teacher
- Open an issue with your question
- Reference the [Documentation Standards](.prompts/documentation-standards.md) for formatting and structure guidance

## Code of Conduct

This is an educational environment. Be respectful, patient, and supportive of learners at all levels.

## License

All documentation is licensed under GPLv3. See [LICENSE](LICENSE) for details.
