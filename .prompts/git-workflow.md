# Git Workflow & Contribution Guidelines

This repository contains the **documentation** for the StratoLab project. Code contributions are managed in separate repositories. These guidelines ensure consistent, high-quality documentation contributions from students, mentors, and community members.

## Branch Naming Conventions

Use descriptive branch names with appropriate prefixes:

### Documentation Changes
- `docs/topic-name` - General documentation updates
  - Example: `docs/gps-troubleshooting`
  - Example: `docs/kickoff`
- `docs/lesson-X` - New lesson content or lesson updates
  - Example: `docs/lesson-9-radio`
  - Example: `docs/lesson-3-updates`
- `docs/fix-topic` - Documentation corrections or clarifications
  - Example: `docs/fix-bmp180-wiring`
  - Example: `docs/fix-spelling-errors`

### Research & Planning
- `research/topic` - Student research documentation
  - Example: `research/battery-analysis`
  - Example: `research/faa-regulations`

### Content Organization
- `refactor/section-name` - Reorganizing or restructuring content
  - Example: `refactor/telemetry-structure`
- `assets/topic` - Adding or updating images, diagrams, or other assets
  - Example: `assets/pico-pinout-diagrams`

### Website/Infrastructure
- `site/feature-name` - Website functionality or styling
  - Example: `site/responsive-images`
- `chore/task` - Maintenance tasks
  - Example: `chore/update-links`

## Commit Message Standards

Use **conventional commit** format for clarity and consistency:

```
type(scope): brief description

Optional longer explanation of what changed and why.

Optional footer with issue references.
```

### Commit Types

- **docs**: Documentation content changes
- **fix**: Corrections to existing documentation
- **feat**: New documentation sections or lessons
- **refactor**: Restructuring content without changing meaning
- **chore**: Maintenance tasks (link updates, formatting)
- **assets**: Adding or updating images, diagrams, files

### Scope Examples

- `lesson-1`, `lesson-2`, etc.
- `balloon`, `telemetry`, `materials`
- `homepage`, `readme`
- `images`, `diagrams`

### Good Commit Message Examples

```
docs(lesson-3): add troubleshooting section for I2C communication

Students were encountering issues with BMP-180 sensor not responding.
Added step-by-step troubleshooting guide with common solutions.

Fixes #42
```

```
feat(balloon): add FAA notification checklist

Created detailed checklist for NOTAM filing process including
contact information and required lead times.
```

```
fix(lesson-1): correct Raspberry Pi Pico pinout diagram

Previous diagram showed incorrect GPIO pin assignments for I2C.
Updated with correct GP4/GP5 pin locations.

SAFETY: This affects actual hardware wiring
```

```
assets(telemetry): add ESP32 wiring photographs

Added photos showing correct orientation and connections for
ESP32 Heltec tracker module lessons.
```

### Bad Commit Message Examples

```
updated stuff
```
❌ Too vague - what was updated?

```
fixed lesson 2
```
❌ Missing type prefix and details about what was fixed

```
docs(lesson-1): changed everything about GPS module setup including wiring, code examples, troubleshooting, added new photos, reorganized sections, fixed typos
```
❌ Too many changes in one commit - break into smaller, focused commits

## Pull Request Process

### Before Creating a PR

1. **Review your changes**
   - Read through all modified documentation
   - Check for spelling and grammar errors
   - Verify all links work correctly
   - Ensure images display properly

2. **Test documentation accuracy**
   - For hardware docs: Verify against actual hardware
   - For lesson content: Test instructions step-by-step
   - For code examples: Ensure they run correctly
   - For external links: Confirm they're still valid

3. **Update related content**
   - Check if index.md or other navigation needs updates
   - Ensure cross-references are accurate
   - Update table of contents if needed

### Creating the Pull Request

1. **Use descriptive PR titles**
   ```
   Good: "Add temperature sensor troubleshooting guide for Lesson 3"
   Bad: "Update docs"
   ```

2. **Write comprehensive PR descriptions**
   Include:
   - What changed and why
   - Testing performed (if applicable)
   - Related issues or discussions
   - Screenshots for visual changes
   - Safety considerations (if applicable)

3. **Use the PR template** (if available)
   - Complete all checklist items
   - Mark N/A for non-applicable items
   - Don't skip safety review questions

### PR Review Requirements

**All PRs require:**
- [ ] At least one mentor/maintainer approval
- [ ] All automated checks passing (if configured)
- [ ] No unresolved review comments

**Additional review needed for:**
- **Safety-critical content**: Hardware wiring, power systems, tracking
  - Requires review from project lead or experienced mentor
- **New lessons**: Must align with curriculum objectives
  - Teacher/educator review recommended
- **FAA/regulatory content**: Must be accurate and current
  - Requires verification against official sources
- **Major reorganization**: Affects multiple lessons or sections
  - Discuss with team before starting

### Merge Strategy

- **Squash and merge** for feature branches with many small commits
- **Regular merge** for collaborative branches with meaningful commit history
- **Main branch protection**: Only maintainers can merge to `main`

## Branch Management

### Working on Your Branch

```bash
# Create a new branch from main
git checkout main
git pull origin main
git checkout -b docs/your-topic-name

# Make your changes and commit regularly
git add .
git commit -m "docs(scope): descriptive message"

# Keep your branch updated with main
git fetch origin
git rebase origin/main

# Push your branch
git push -u origin docs/your-topic-name
```

### Handling Merge Conflicts

1. **Communicate with your team** - Check if others are working on the same files
2. **Update your branch** regularly to minimize conflicts
3. **Ask for help** - Mentors can assist with complex conflicts

## Documentation-Specific Guidelines

### Safety Considerations

Documentation errors in StratoLab can have **real-world consequences**:

- **Hardware wiring errors** → Damaged components or safety hazards
- **Incorrect procedures** → Failed balloon launches or lost payloads
- **Wrong specifications** → Non-compliant flights or regulatory violations

**Always include `SAFETY:` prefix in commits affecting:**
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

### Educational Quality

Remember your audience: **students and first-time contributors**

- Use clear, accessible language
- Define technical terms on first use
- Include "why" not just "how"
- Provide context for decisions
- Link to additional learning resources
- Encourage questions and critical thinking

### Accessibility

Make content accessible to all learners:

- Add alt text to all images: `![Description of image](path/to/image.png)`
- Use descriptive link text (not "click here")
- Structure content with proper headings
- Use tables for tabular data
- Consider colorblind-friendly color schemes in diagrams

## Common Scenarios

### Adding a New Lesson

1. Create branch: `docs/lesson-X-topic`
2. Follow lesson structure template (see documentation-standards.md)
3. Include all required sections
4. Add to navigation in index.md
5. Test all instructions personally
6. Request review from educator/mentor

### Fixing Documentation Errors

1. Create branch: `docs/fix-specific-issue`
2. Make targeted fix
3. If safety-related, flag in commit message and PR
4. Link to issue or discussion if applicable

### Adding Research Content

1. Create branch: `research/topic-name`
2. Follow research documentation structure
3. Include sources and citations
4. Present findings clearly
5. Connect to related lessons/content

### Updating Images/Diagrams

1. Create branch: `assets/description`
2. Use consistent naming: `component-name-view.jpg`
3. Optimize file sizes (< 500KB when possible)
4. Update all references to the image
5. Include image attribution if not original

## Getting Help

- **First time contributing?** Ask your mentor or teacher for guidance
- **Stuck on Git?** Check GitHub's documentation or ask for help
- **Documentation questions?** Reference documentation-standards.md
- **Found an issue?** Create a GitHub issue to discuss before starting work

## Code of Conduct

This is an **educational environment**. We expect:

- **Respect** for all contributors regardless of experience level
- **Patience** when reviewing student contributions
- **Constructive feedback** that helps learners improve
- **Collaboration** over competition
- **Safety first** always

## Resources

- [GitHub Flow Guide](https://guides.github.com/introduction/flow/)
- [Conventional Commits](https://www.conventionalcommits.org/)
- [Writing Good Commit Messages](https://chris.beams.io/posts/git-commit/)
- [Markdown Guide](https://www.markdownguide.org/)

---

**Remember**: Good documentation enables safe, successful balloon launches and meaningful learning experiences. Take pride in your contributions!
