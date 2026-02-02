# AI Agent Guidelines for StratoLab Documentation

## Project Overview

**StratoLab** is an educational STEM project that enables schools, community groups, and youth organizations to launch high-altitude balloons to the stratosphere (90,000+ feet). This repository contains **instructional documentation only** - lesson plans, assembly guides, hardware instructions, and educational materials written in Markdown.

### Key Facts
- **Repository Type**: Documentation only (no production code)
- **Platform**: GitLab Pages (static site)
- **Primary Audience**: Students (beginners), teachers, mentors
- **Code Location**: Separate repository for Arduino/Python/C implementations
- **Content Format**: Markdown, images, diagrams
- **Educational Focus**: Learning programming, electronics, and team building
- **Real-World Impact**: Documentation errors can affect hardware safety and balloon launches

## Critical Context for AI Agents

### Safety-First Mindset

This is not typical software documentation. Errors in this documentation can have **real-world safety consequences**:

- ❌ **Incorrect wiring diagrams** → Damaged components, safety hazards
- ❌ **Wrong procedures** → Failed launches, lost payloads (expensive!)
- ❌ **Incorrect specs** → FAA violations, regulatory issues
- ❌ **Missing polarity warnings** → Component failure, potential fire hazards
- ❌ **Temperature limit errors** → Equipment failure at -60°C to +40°C

**Always prioritize safety verification over speed of delivery.**

### Educational Tone Requirements

Remember your audience: **students encountering these concepts for the first time**.

✅ **Do:**
- Use second person ("you") to directly address students
- Be encouraging and supportive
- Ask questions to promote critical thinking
- Define technical terms on first use
- Explain "why" not just "how"
- Include links to learning resources

❌ **Don't:**
- Use overly formal or distant language ("the student shall...")
- Be condescending ("this is super easy!")
- Skip explanations ("just do what I say")
- Assume prior knowledge without verification
- Use jargon without definitions

## Quick Start for AI Agents

### Essential Reading (In Order)

1. **First**: Read this entire AGENTS.md file
2. **Second**: Review [`.prompts/git-workflow.md`](.prompts/git-workflow.md) - Git conventions and contribution process
3. **Third**: Review [`.prompts/documentation-standards.md`](.prompts/documentation-standards.md) - Content quality standards

### Before Making Any Changes

- [ ] Read the existing file you're modifying completely
- [ ] Check related files for cross-references that need updating
- [ ] Verify your changes against documentation standards
- [ ] Consider safety implications
- [ ] Test any instructions if hardware-related
- [ ] Ensure all links work
- [ ] Verify images display correctly

## Repository Structure

```
stratolab.github.io/
├── .prompts/                      # Contribution guidelines for AI/humans
│   ├── git-workflow.md           # Git conventions, branch naming, commits
│   └── documentation-standards.md # Content quality, lesson structure, safety
├── balloon/                       # Balloon assembly & launch documentation
│   ├── overview.md               # FAA regulations, safety, planning
│   ├── supplies.md               # Materials needed for balloon
│   ├── assembly.md               # Assembly instructions
│   ├── prediction.md             # Flight prediction tools
│   └── checklist.md              # Launch day checklist
├── telemetry/                     # Microcontroller lessons by platform
│   ├── raspberry-pi-pico/
│   │   ├── hardware/README.md    # Hardware overview
│   │   ├── workbench/README.md   # Development environment setup
│   │   └── python/lesson-N/README.md  # Individual lessons
│   ├── arduino/
│   │   ├── workbench/README.md
│   │   └── c/lesson-N/README.md
│   └── esp32-heltec-tracker/
│       └── c/lesson-N/README.md
├── assets/
│   └── images/                    # Project images, diagrams, photos
├── index.md                       # Main landing page with navigation
├── materials.md                   # Complete materials list & cost estimates
├── initial-research.md            # Research planning guide
├── .github/
│   └── PULL_REQUEST_TEMPLATE.md  # PR checklist (testing, safety, quality)
├── CONTRIBUTING.md                # Human contributor guide
└── AGENTS.md                      # (This file) AI agent guidelines
```

## Documentation Standards (Inline Summary)

Full details: [`.prompts/documentation-standards.md`](.prompts/documentation-standards.md)

### Required Lesson Structure

Every lesson **must** follow this template:

```markdown
# Lesson X: [Descriptive Title]

#### Objectives:
- Students will [specific, measurable learning objective]
- [2-4 objectives recommended]
- Each objective should start with an action verb

<br><br>

## What you will be using:
- [Component Name](link to product/specs)
  <img src="path/to/image.jpg" width="50%">
- [Additional components...]

## What you will be learning:

[Educational content with subsections]

### [Concept 1]
[Explanation with context and "why"]

### [Concept 2]
[Explanation with context]

## Let's give it a try!

1. [Step-by-step instructions]
2. [Numbered, sequential steps]
3. [Clear and testable]

**Congratulations! You have successfully completed Lesson X.**

## Troubleshooting

* **Error message or symptom in bold**

  Clear explanation of cause.

  Steps to resolve:
  1. First thing to try
  2. Second thing to try
  3. When to ask for help
```

### Safety Warning Format

Use this exact format for safety-critical content:

```markdown
> ⚠️ **WARNING: [Type of Hazard]**
> [Clear explanation of the danger and how to avoid it]
```

**Examples:**

```markdown
> ⚠️ **POLARITY WARNING**
> The BMP-180 sensor can be damaged if power is connected backwards.
> Always double-check VIN goes to 3.3V and GND goes to ground before
> powering on.

> ⚠️ **STATIC ELECTRICITY**
> Microcontrollers and sensors are sensitive to static discharge.
> Touch a grounded metal surface before handling components.

> ⚠️ **FAA COMPLIANCE REQUIRED**
> High altitude balloon launches are regulated by FAA Part 101.
> Payload weight must not exceed 4 pounds (including all components).
```

### Image Requirements

**All images must include:**
- Descriptive alt text (accessibility requirement)
- Optimized file size (< 500KB preferred)
- Descriptive kebab-case filename
- Proper width sizing when needed

```markdown
<!-- Good examples -->
![Raspberry Pi Pico microcontroller showing USB port and GPIO pins](image.jpg)

<img src="assets/images/breadboard-wiring.jpg" width="50%">

<!-- Bad examples - missing alt text -->
![image](pic.jpg) ❌
![](diagram.png) ❌
```

### Wiring Diagrams

**Always include:**
1. Multiple views (top, side, closeup as needed)
2. Pin connection table
3. Wire color coding:
   - **Red**: Power (VCC, 3.3V, 5V)
   - **Black/Brown**: Ground (GND)
   - **Other colors**: Signal lines
4. Polarity warnings for relevant components
5. Labels on all components and pins

**Example pin table:**

```markdown
| Raspberry Pi Pico Pin | BMP-180 Pin | Wire Color |
|-----------------------|-------------|------------|
| GPIO 4 (SDA)          | SDA         | Blue       |
| GPIO 5 (SCL)          | SCL         | Yellow     |
| 3.3V (OUT)            | VIN         | Red        |
| GND                   | GND         | Black      |
```

### Code in Documentation

Code examples in lessons must be **heavily commented** for educational purposes:

```python
# Good - Educational comments explaining WHY
# Initialize I2C communication on pins 4 (SDA) and 5 (SCL)
# The BMP-180 sensor uses I2C protocol to communicate
i2c = machine.I2C(0, scl=machine.Pin(5), sda=machine.Pin(4), freq=400000)

# Scan I2C bus to find connected devices
# This returns a list of addresses (in decimal) for all devices found
devices = i2c.scan()

# Bad - Insufficient explanation
i2c = machine.I2C(0, scl=machine.Pin(5), sda=machine.Pin(4), freq=400000)  # init I2C ❌
devices = i2c.scan()  # scan ❌
```

**Always include expected output:**

```markdown
When you run this code, you should see output similar to:

```
Temperature: 22.5°C
Pressure: 1013.25 hPa
Altitude: 45.2 meters
```

If you see different values, that's normal! The sensor reads your current environment.
```

### Accessibility Standards

- **Alt text**: Required for all images
- **Link text**: Descriptive (not "click here")
- **Headings**: Properly nested (don't skip levels)
- **Lists**: Use for 3+ related items
- **Color**: Not sole indicator of information
- **Language**: Clear, simple, short paragraphs (3-5 sentences)

## Git Workflow (Inline Summary)

Full details: [`.prompts/git-workflow.md`](.prompts/git-workflow.md)

### Branch Naming Conventions

Use descriptive prefixes:

- `docs/topic-name` - General documentation updates
  - Example: `docs/gps-troubleshooting`
- `docs/lesson-X` - New lesson or lesson updates
  - Example: `docs/lesson-9-radio`
- `docs/fix-topic` - Documentation corrections
  - Example: `docs/fix-bmp180-wiring`
- `research/topic` - Student research documentation
  - Example: `research/battery-analysis`
- `assets/topic` - Images, diagrams, media
  - Example: `assets/pico-pinout-diagrams`
- `refactor/section` - Content reorganization
  - Example: `refactor/telemetry-structure`

### Commit Message Format

Use **conventional commit** format:

```
type(scope): brief description

Optional longer explanation of what changed and why.

Optional footer with issue references.
```

**Types:**
- `docs`: Documentation content changes
- `fix`: Corrections to existing documentation
- `feat`: New documentation sections or lessons
- `refactor`: Restructuring content without changing meaning
- `chore`: Maintenance tasks (link updates, formatting)
- `assets`: Adding or updating images, diagrams

**Scopes:**
- `lesson-1`, `lesson-2`, etc.
- `balloon`, `telemetry`, `materials`
- `homepage`, `readme`
- `images`, `diagrams`

**Good commit examples:**

```
docs(lesson-3): add troubleshooting section for I2C communication

Students were encountering issues with BMP-180 sensor not responding.
Added step-by-step troubleshooting guide with common solutions.

Fixes #42
```

```
fix(lesson-1): correct Raspberry Pi Pico pinout diagram

Previous diagram showed incorrect GPIO pin assignments for I2C.
Updated with correct GP4/GP5 pin locations.

SAFETY: This affects actual hardware wiring
```

### Safety Commit Prefix

**Always include `SAFETY:` prefix** in commits affecting:
- Hardware wiring diagrams or pinouts
- Power/battery specifications
- FAA regulations or procedures
- Temperature/environmental limits
- GPS/tracking systems

Example:
```
fix(balloon): correct payload weight limit calculation

Previous documentation stated 6lb limit, but FAA Part 101
specifies 4lb limit for unregulated flights.

SAFETY: This affects FAA compliance
```

## Safety-Critical Content Checklist

When working with these topics, **extra verification is required**:

### Hardware Wiring & Pinouts
- [ ] Verify against actual hardware datasheets
- [ ] Double-check pin numbers and functions
- [ ] Confirm voltage levels (3.3V vs 5V)
- [ ] Verify I2C/SPI/UART addresses and protocols
- [ ] Include polarity warnings for polarized components
- [ ] Show multiple views/angles in photos
- [ ] Test instructions personally before committing

### Power Systems
- [ ] Verify voltage specifications
- [ ] Check current draw calculations
- [ ] Confirm battery chemistry compatibility with temperature range
- [ ] Include polarity warnings
- [ ] Note discharge rates and capacity
- [ ] Warn about charging in extreme temperatures

### FAA & Regulatory Content
- [ ] Verify against official FAA Part 101 regulations
- [ ] Check weight limits (4 pounds for unrestricted)
- [ ] Confirm NOTAM filing requirements
- [ ] Include current contact information
- [ ] Note required lead times
- [ ] Reference official sources

### Environmental Specifications
- [ ] Temperature range: -60°C to +40°C (stratosphere to ground)
- [ ] Component temperature ratings verified
- [ ] Battery performance in cold noted
- [ ] Altitude limits for components
- [ ] Pressure considerations

### GPS & Tracking
- [ ] GPS coordinate accuracy expectations
- [ ] Satellite visibility requirements
- [ ] Cold start vs warm start times
- [ ] APRS configuration requirements (if applicable)
- [ ] Backup tracking methods

## Common AI Agent Tasks

### Task 1: Creating a New Lesson

1. **Choose appropriate directory** based on platform:
   - Raspberry Pi Pico: `/telemetry/raspberry-pi-pico/python/lesson-N/`
   - Arduino: `/telemetry/arduino/c/lesson-N/`
   - ESP32: `/telemetry/esp32-heltec-tracker/c/lesson-N/`

2. **Follow lesson template exactly** (see structure above)

3. **Include all required sections**:
   - Objectives (4 hashes: `####`)
   - What you will be using (with images)
   - What you will be learning (educational content)
   - Let's give it a try! (step-by-step)
   - Troubleshooting

4. **Update navigation**:
   - Add link to `index.md`
   - Update parent README if applicable
   - Check for related lesson cross-references

5. **Verify before committing**:
   - All images have alt text
   - All links work
   - Code examples tested
   - Safety warnings included
   - Troubleshooting covers common issues

### Task 2: Fixing Documentation Errors

1. **Assess severity**:
   - **Safety-critical** (wiring, specs, regulations): Immediate fix + SAFETY prefix
   - **Functional** (broken links, incorrect steps): High priority
   - **Cosmetic** (typos, formatting): Normal priority

2. **Make targeted fixes**:
   - Don't rewrite entire sections unnecessarily
   - Preserve educational tone and style
   - Maintain consistency with surrounding content

3. **Update related content**:
   - Check cross-references in other lessons
   - Update index/navigation if needed
   - Fix in all affected locations

4. **Use appropriate branch**:
   - `docs/fix-specific-issue` for targeted fixes
   - Include issue number if applicable

### Task 3: Adding/Updating Images

1. **Image requirements**:
   - Format: JPG for photos, PNG for diagrams/screenshots
   - Size: < 500KB preferred (use compression)
   - Resolution: 1200-1600px width typical
   - Naming: `component-name-description.jpg` (kebab-case)
   - Location: `assets/images/` or lesson-specific `assets/`

2. **Always include**:
   - Descriptive alt text
   - Proper width attribute if needed
   - Image attribution if not original

3. **For wiring diagrams**:
   - Include source files (Fritzing, draw.io) in repository
   - Multiple views (top, side, closeup)
   - Clear labels on all components
   - Consistent wire colors
   - Accompanying pin table

4. **Update references**:
   - Find all locations where image is used
   - Update file paths if moving
   - Check that image displays correctly in all contexts

### Task 4: Adding Troubleshooting Content

1. **Format**:
   ```markdown
   ## Troubleshooting

   * **Symptom or error message in bold**

     Clear explanation of what causes this issue.

     Steps to resolve:
     1. First thing to try
     2. Second thing to try
     3. When to ask for help
   ```

2. **Include**:
   - Exact error messages (in code formatting)
   - Observable symptoms
   - Root cause explanation
   - Step-by-step resolution
   - When to escalate to mentor

3. **Common issues to address**:
   - Connection/wiring problems
   - I2C device not found
   - Incorrect sensor readings
   - Software installation issues
   - Upload/connection failures
   - Power issues

### Task 5: Updating Cross-References

When modifying content, check these for updates:

- `index.md` - Main navigation page
- Parent directory README files
- Related lessons (prerequisites, follow-ups)
- `materials.md` - If adding new components
- `initial-research.md` - If affecting research areas
- Balloon guides - If affecting launch procedures

## File Naming Conventions

### Lesson Files
- Always `README.md` inside lesson directory
- Path: `/telemetry/{platform}/{language}/lesson-{N}/README.md`
- Example: `/telemetry/raspberry-pi-pico/python/lesson-3/README.md`

### Image Files
- Descriptive kebab-case: `raspberry-pi-pico-top-view.jpg`
- Include component name and view/purpose
- Examples:
  - `breadboard-wiring-diagram.png`
  - `bmp180-sensor-both-sides.jpg`
  - `gps-module-neo-6m.jpg`

### Markdown Files
- Lowercase with hyphens: `initial-research.md`
- Descriptive names: `materials.md`, `overview.md`
- Exception: `README.md` (uppercase per convention)
- Exception: `CONTRIBUTING.md`, `AGENTS.md` (uppercase for visibility)

## Testing Requirements

### Before Suggesting Changes

**For lesson content:**
- [ ] Can a beginner follow these instructions?
- [ ] Are all technical terms defined?
- [ ] Do questions promote critical thinking?
- [ ] Is the educational "why" explained?
- [ ] Are safety warnings present where needed?

**For hardware instructions:**
- [ ] Have these been tested on actual hardware?
- [ ] Do pin numbers match component datasheets?
- [ ] Are voltage levels correct (3.3V vs 5V)?
- [ ] Is polarity clearly marked?
- [ ] Are wire colors consistent?
- [ ] Is there a troubleshooting section?

**For all documentation:**
- [ ] Do all links work?
- [ ] Do images display correctly?
- [ ] Is alt text present and descriptive?
- [ ] Is Markdown properly formatted?
- [ ] Are headings properly nested?
- [ ] Is spelling/grammar correct?

**For code examples:**
- [ ] Does code actually run?
- [ ] Are comments educational (explain WHY)?
- [ ] Is expected output shown?
- [ ] Are error messages explained?
- [ ] Is code style consistent with project?

## What AI Agents Should NOT Do

❌ **Don't:**
- Change content without understanding context
- Remove safety warnings to "simplify" content
- Make wiring diagram changes without verification
- Skip testing hardware instructions
- Use technical jargon without definitions
- Write in first person ("I will show you...")
- Create overly formal academic tone
- Skip accessibility features (alt text, descriptive links)
- Batch unrelated changes in single commit
- Modify FAA/regulatory content without verification

✅ **Do:**
- Read existing content thoroughly first
- Ask clarifying questions when uncertain
- Preserve educational tone and style
- Maintain consistency with existing content
- Include comprehensive safety information
- Test instructions when possible
- Use second person ("you") for student-facing content
- Break complex changes into focused commits
- Reference official sources for regulations

## Coordination with Code Repository

This repository is **documentation only**. A separate repository exists for:
- Arduino C/C++ code
- MicroPython code for Raspberry Pi Pico
- ESP32 C code
- Library files and dependencies

**When documentation and code need coordination:**
- Cross-reference between repos in commit messages
- Note code repository changes that affect documentation
- Maintain consistency in terminology
- Coordinate major releases
- Document code examples must match actual code repository

## Links to Full Guidelines

For comprehensive details, always reference these files:

- **[Git Workflow & Contribution Guidelines](.prompts/git-workflow.md)**
  - Complete branch naming conventions
  - Detailed commit message standards
  - Pull request process
  - Merge strategies
  - Conflict resolution

- **[Documentation Standards & Quality Guidelines](.prompts/documentation-standards.md)**
  - Complete lesson structure template
  - Writing style guide in detail
  - All formatting standards
  - Visual content standards (images, diagrams, tables)
  - Complete accessibility guidelines
  - Quality checklist
  - Peer review process

## Educational Philosophy Reminder

StratoLab exists to empower students through hands-on STEM learning. Every piece of documentation should:

1. **Inspire curiosity** - Ask questions, encourage exploration
2. **Build confidence** - Celebrate small wins, provide clear guidance
3. **Ensure safety** - Never compromise on safety information
4. **Promote understanding** - Explain concepts, not just procedures
5. **Enable success** - Provide troubleshooting, support, resources
6. **Foster collaboration** - Encourage teamwork and peer learning

**Remember**: These students are launching real balloons to the stratosphere. The documentation you help create directly impacts their learning experience and project success.

---

**Questions or need clarification?** Reference the comprehensive guides in `.prompts/` or ask the project maintainers.

**Found an issue in this file?** Open an issue or submit a PR to improve these guidelines!

*Last Updated: 2026-02-02*
*Maintainer: Project Leads/Mentors*
