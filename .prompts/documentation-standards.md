# Documentation Standards & Quality Guidelines

StratoLab documentation serves multiple audiences: students learning programming and electronics, teachers delivering lessons, and mentors guiding the project. These standards ensure our documentation is **clear, accurate, safe, and educational**.

## Documentation Philosophy

### Core Principles

1. **Clarity over cleverness** - Use straightforward language
2. **Safety first** - Highlight hazards and proper procedures
3. **Learning-focused** - Encourage understanding, not just following steps
4. **Tested and verified** - All instructions must work on actual hardware
5. **Accessible** - Content should be approachable for beginners
6. **Consistent** - Similar content should look and feel similar

### Audience Awareness

Remember who reads our documentation:

- **Students**: May be encountering these concepts for the first time
- **Teachers**: Need to understand content well enough to teach it
- **Mentors**: Need quick reference and troubleshooting information
- **Parents/Community**: May be supporting students or securing materials

## Lesson Structure Template

All lesson content should follow this consistent structure:

### Required Sections

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

[Educational content with subsections as needed]

### [Concept 1]
[Explanation with context]

### [Concept 2]
[Explanation with context]

## Let's give it a try!

1. [Step-by-step instructions]
2. [With numbered steps]
3. [Clear and testable]

**Congratulations! You have successfully completed Lesson X.**

## Troubleshooting

* `Error message or symptom`

  [Clear explanation and solution steps]
```

### Optional Sections

- **Prerequisites**: Link to prior lessons or required knowledge
- **Time Required**: Estimated duration (typical class is 45-60 minutes)
- **Additional Resources**: Links for deeper learning
- **Challenge Extensions**: Advanced activities for fast learners

## Writing Style Guide

### Voice and Tone

- **Use second person** ("you") to directly address students
- **Be encouraging** but not condescending
- **Ask questions** to promote critical thinking
- **Be conversational** while remaining professional

**Good Examples:**
```markdown
What are some things that use GPS technology that you know of?

Take some time to read the comments in this code so you understand what is happening.

IT's VERY important to keep in mind polarity.
```

**Avoid:**
```markdown
The student should now proceed to... ❌ (too formal/distant)

This is super easy and anyone can do it! ❌ (condescending)

Just do exactly what I say. ❌ (doesn't encourage understanding)
```

### Technical Terms

1. **Define on first use** in each document
2. **Link to resources** for deeper understanding (Wikipedia, official docs)
3. **Use consistent terminology** throughout all documentation
4. **Include pronunciation** for acronyms when helpful

**Example:**
```markdown
This device uses something called [I2C](https://en.wikipedia.org/wiki/I²C)
which allows many devices to be connected to the same pins on the microcontroller
but have unique addresses to identify each component.
```

### Formatting Standards

#### Headings

- Use ATX-style headings (`#` symbols)
- One `#` (H1) for lesson title only
- `##` (H2) for major sections
- `###` (H3) for subsections
- `####` (H4) for objectives (convention in existing lessons)
- Don't skip heading levels

#### Lists

- Use `-` for unordered lists
- Use `1.` for ordered/sequential steps
- Indent sub-items consistently (2 spaces)
- Use lists for 3+ related items

#### Emphasis

- **Bold** for important warnings, key terms, UI elements
- *Italics* for slight emphasis or titles
- `Code formatting` for commands, file names, error messages, technical values

#### Links

- Use descriptive link text: `[Arduino basics tutorial](url)`
- Not: `Click [here](url)` ❌
- Verify all links work before committing
- Use relative links for internal content: `[Materials](materials.md)`
- Use absolute URLs for external resources

## Visual Content Standards

### Images

#### Image Requirements

- **File format**: JPG for photos, PNG for diagrams/screenshots
- **File size**: Optimize to < 500KB when possible (use compression tools)
- **Resolution**: Clear enough to see details (usually 1200-1600px width)
- **Naming**: Descriptive kebab-case: `raspberry-pi-pico-top-view.jpg`
- **Location**: Store in `assets/images/` or lesson-specific `assets/` folder

#### Image Usage

```markdown
<!-- Standard image -->
![Descriptive alt text](path/to/image.jpg)

<!-- Sized image -->
<img src="path/to/image.jpg" width="50%">

<!-- Styled image (use sparingly) -->
<img
    style="display: block;
           margin-left: auto;
           margin-right: auto;
           width: 30%;"
    src="assets/images/logo.png"
    alt="StratoLab logo">
```

#### Alt Text Requirements

All images MUST include descriptive alt text for accessibility:

```markdown
<!-- Good alt text -->
![Raspberry Pi Pico microcontroller showing USB port and GPIO pins](image.jpg)

![Breadboard wiring diagram showing BMP-180 sensor connected to GPIO pins 4 and 5](diagram.png)

<!-- Bad alt text -->
![image](image.jpg) ❌
![pic](diagram.png) ❌
```

### Wiring Diagrams and Pinouts

#### Requirements

- **Multiple views**: Top view, side view, closeup as needed
- **Pin tables**: Always include table with pin connections
- **Color coding**: Use consistent wire colors where possible
  - Red: Power (VCC, 3.3V, 5V)
  - Black/Brown: Ground (GND)
  - Other colors: Signal lines
- **Labels**: Clearly label components and pins
- **Polarity warnings**: Highlight components with polarity requirements

#### Example Pinout Table

```markdown
| Raspberry Pi Pico Pin | BMP-180 Pin | Wire Color |
|-----------------------|-------------|------------|
| GPIO 4 (SDA)          | SDA         | Blue       |
| GPIO 5 (SCL)          | SCL         | Yellow     |
| 3.3V (OUT)            | VIN         | Red        |
| GND                   | GND         | Black      |
```

### Diagrams

- Use vector graphics (SVG) when possible for scalability
- Include source files (Fritzing, draw.io) in repository
- Maintain consistent style across all diagrams
- Use high contrast colors
- Include legends when needed

## Code Documentation in Lessons

When including code examples in documentation:

### Code Blocks

````markdown
```python
# Use the appropriate language tag
import machine
import time

# Include comments explaining key concepts
led = machine.Pin(25, machine.Pin.OUT)  # GPIO 25 is the onboard LED

# Comments should explain WHY, not just WHAT
while True:
    led.toggle()  # Toggle LED state
    time.sleep(1)  # Wait 1 second
```
````

### Code Comments

Code within lessons should be **heavily commented** for educational purposes:

**Good Example:**
```python
# Initialize I2C communication on pins 4 (SDA) and 5 (SCL)
# The BMP-180 sensor uses I2C protocol to communicate
i2c = machine.I2C(0, scl=machine.Pin(5), sda=machine.Pin(4), freq=400000)

# Scan I2C bus to find connected devices
# This returns a list of addresses (in decimal) for all devices found
devices = i2c.scan()
```

**Insufficient Example:**
```python
i2c = machine.I2C(0, scl=machine.Pin(5), sda=machine.Pin(4), freq=400000)  # init I2C
devices = i2c.scan()  # scan
```

### Expected Output

Always show what students should see:

```markdown
When you run this code, you should see output similar to:

```
Temperature: 22.5°C
Pressure: 1013.25 hPa
Altitude: 45.2 meters
```

If you see different values, that's normal! The sensor reads your current environment.
```

### Code Attribution

If using code from external sources:
- Include source URL
- Respect licenses
- Modify for educational clarity when needed
- Document what changed and why

## Safety Callouts and Warnings

Safety is **critical** in StratoLab. Use consistent, visible formatting for safety information.

### Safety Warning Format

```markdown
> ⚠️ **WARNING: [Type of Hazard]**
> [Clear explanation of the danger and how to avoid it]

> ⚠️ **POLARITY WARNING**
> The BMP-180 sensor can be damaged if power is connected backwards.
> Always double-check VIN goes to 3.3V and GND goes to ground before
> powering on.
```

### Common Safety Topics

#### Static Electricity

```markdown
> ⚠️ **STATIC ELECTRICITY**
> Microcontrollers and sensors are sensitive to static discharge.
> Touch a grounded metal surface before handling components.
```

#### Polarity

```markdown
> ⚠️ **POLARITY CRITICAL**
> LED's have polarity - the longer lead (anode) is positive, shorter lead
> (cathode) is negative. Connecting backwards may damage the LED.
```

#### Magic Smoke

Use the project's established terminology:

```markdown
We don't want to release the [magic smoke](https://en.m.wikipedia.org/wiki/Magic_smoke)!!
```

#### Power Disconnection

```markdown
> ⚠️ **POWER OFF WHEN WIRING**
> Always disconnect the microcontroller from USB power before adding
> or changing wire connections. This prevents short circuits.
```

#### Temperature Hazards

```markdown
> ⚠️ **EXTREME TEMPERATURES**
> The balloon will encounter temperatures from -60°C to +40°C.
> Components must be rated for these conditions. Standard rechargeable
> batteries may fail in extreme cold.
```

#### FAA Regulations

```markdown
> ⚠️ **FAA COMPLIANCE REQUIRED**
> High altitude balloon launches are regulated by FAA Part 101.
> Payload weight must not exceed 4 pounds (including all components).
> See [balloon/overview.md] for complete regulations.
```

## Troubleshooting Sections

Every lesson should include a troubleshooting section addressing common issues.

### Troubleshooting Format

```markdown
## Troubleshooting

* **Symptom or error message in bold**

  Clear explanation of what causes this issue.

  Steps to resolve:
  1. First thing to try
  2. Second thing to try
  3. When to ask for help

* **Second issue**

  [Similar format]
```

### Good Troubleshooting Example

```markdown
## Troubleshooting

* **ERROR: `Couldn't find the device automatically.`**

  If you encounter this error it's likely a result of MicroPython not being
  loaded onto the Raspberry Pi Pico. This usually occurs with a brand new
  Pi Pico device.

  Follow the steps in section "Connecting a brand new Raspberry Pi Pico"
  above to install MicroPython to the controller.

* **Sensor returns `0` or `NaN` values**

  This usually indicates a wiring or I2C communication problem.

  1. Check all wire connections match the pinout table
  2. Ensure sensor is powered (check voltage with multimeter if available)
  3. Run an I2C scan to verify sensor address is detected
  4. Try reseating all connections
  5. Ask mentor to verify wiring with you
```

## Cross-References and Navigation

### Internal Linking

- Link to related lessons: `[Lesson 1](../lesson-1/README.md)`
- Link to other sections: `[Materials Guide](materials.md)`
- Link to specific anchors: `[Troubleshooting Section](#troubleshooting)`

### Navigation Updates

When adding new content, update:
- `index.md` with new lesson links
- Parent README files
- Related lesson references
- Table of contents (if present)

## Special Content Types

### Research Documentation

For student research (like initial-research.md):

```markdown
## [Research Topic]

- [Key question or problem to investigate]
- [Sub-questions or considerations]
- [Constraints or assumptions]
- Any other items of note to share from your research or further questions?
```

### Materials Lists

```markdown
- [Quantity] × [Component Name](link to product or specs)
  - [Key specifications]
  - [Approximate cost]
  - [Recommended supplier]
```

### Checklists

Use GitHub-flavored markdown task lists:

```markdown
- [ ] Task to complete
- [ ] Another task
- [x] Completed task
```

## Accessibility Guidelines

Make content accessible to all learners:

### Text Accessibility

- Use clear, simple language when possible
- Define jargon and acronyms
- Use short paragraphs (3-5 sentences)
- Break up long content with headings and lists

### Visual Accessibility

- All images must have descriptive alt text
- Don't rely on color alone to convey information
- Use sufficient contrast (test with colorblind simulators)
- Make text resizable (avoid fixed font sizes)

### Cognitive Accessibility

- One main concept per section
- Consistent layout and structure
- Clear step numbering
- Visual breaks between sections

## Quality Checklist

Before submitting documentation, verify:

### Content Quality

- [ ] Objectives are clear and measurable
- [ ] All steps tested on actual hardware
- [ ] Technical terms defined
- [ ] Questions included to promote thinking
- [ ] Links verified and working
- [ ] Cross-references accurate

### Safety

- [ ] Safety warnings included where needed
- [ ] Polarity clearly marked
- [ ] Temperature/environmental limits noted
- [ ] FAA/regulatory compliance mentioned if applicable

### Visual Content

- [ ] All images have descriptive alt text
- [ ] Images properly sized and optimized
- [ ] Diagrams are clear and labeled
- [ ] Wiring diagrams match text descriptions

### Code Quality

- [ ] Code examples tested and working
- [ ] Sufficient comments for learning
- [ ] Expected output documented
- [ ] Error messages explained

### Formatting

- [ ] Markdown renders correctly
- [ ] Headings properly nested
- [ ] Lists formatted consistently
- [ ] Code blocks have language tags

### Accessibility

- [ ] Text is clear and readable
- [ ] Color is not sole indicator
- [ ] Content is logically organized
- [ ] Navigation is intuitive

## Getting Feedback

### Peer Review

- Have another student or mentor review
- Test instructions with someone unfamiliar with the topic
- Ask: "Is anything unclear or confusing?"
- Incorporate feedback before PR

### Student Testing

Best documentation comes from actual use:
- Test lessons in classroom settings
- Watch where students get stuck
- Note common questions
- Update documentation based on real experiences

## Continuous Improvement

Documentation is never "done":

- Update based on student feedback
- Incorporate new discoveries
- Fix errors as found
- Improve clarity over time
- Keep up with hardware/software changes

## Resources

- [Markdown Guide](https://www.markdownguide.org/)
- [GitHub Flavored Markdown](https://github.github.com/gfm/)
- [Writing Accessible Documentation](https://developers.google.com/style/accessibility)
- [Technical Writing Guidelines](https://developers.google.com/tech-writing)

---

**Remember**: Quality documentation empowers students to learn confidently and launch successfully. Every detail matters when students are learning new concepts and working with real hardware that will fly to the stratosphere!
