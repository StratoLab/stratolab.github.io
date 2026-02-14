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

**Using the helper script (recommended for macOS/Linux):**

```bash
./serve.sh
```

Then open your browser to [http://localhost:8000](http://localhost:8000)

**Script options:**
- `./serve.sh -o` — Start server and open browser automatically
- `./serve.sh -p 3000` — Use a different port

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
different port: `./serve.sh -p 3001`

**Changes not appearing:**

Hard refresh your browser:
- Windows/Linux: `Ctrl+Shift+R`
- macOS: `Cmd+Shift+R`

**"Python not found" error:**

Install Python 3 from [python.org/downloads](https://www.python.org/downloads/)

**"Permission denied" when running serve.sh:**

Make the script executable: `chmod +x serve.sh`

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
