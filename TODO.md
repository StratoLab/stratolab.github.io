# StratoLab Contribution Guidelines - Implementation TODO

This document tracks the remaining phases for implementing comprehensive contribution guidelines across the StratoLab project.

## ✅ Phase 1: Completed

Documentation repository foundational guidelines:

- [x] `.prompts/git-workflow.md` - Git contribution guidelines for documentation
- [x] `.prompts/documentation-standards.md` - Documentation quality standards

## Phase 2: Code Repository Guidelines (Near-term)

These prompts should be created in the **code/telemetry repository** (not this documentation repository):

### 2.1 Code Quality Standards Prompt

**File**: `.prompts/code-quality.md` (in code repository)

**Purpose**: Maintain reliable, testable code for embedded systems

**Key Content:**
- Language-specific standards (Python/MicroPython, C/C++ for Arduino/ESP32)
- Educational code principles (clarity over cleverness)
- Memory management for embedded systems
- Testing requirements for each microcontroller platform
- Hardware testing procedures (bench testing before flight)
- Safety-critical code review requirements (GPS, power management, data logging)
- Power consumption considerations
- Temperature/environmental testing protocols

**Priority**: HIGH - Ensures code reliability for real balloon launches

### 2.2 Hardware Contributions Prompt

**File**: `.prompts/hardware-contributions.md` (in code repository)

**Purpose**: Ensure accurate, safe hardware interface code

**Key Content:**
- Pin configuration standards
- I2C/SPI/UART communication best practices
- Component initialization procedures
- Sensor calibration requirements
- Power management code patterns
- Error handling for hardware failures
- Logging and debugging practices
- Integration testing with multiple sensors
- Flight-ready validation checklist

**Priority**: HIGH - Critical for safety and successful launches

---

## Phase 3: Code Repository Research Guidelines (As needed)

### 3.1 Research Documentation for Code

**File**: `.prompts/research-documentation.md` (in code repository)

**Purpose**: Guide documentation of technical research and problem-solving

**Key Content:**
- Technical research structure (problem statement, findings, solutions)
- Performance benchmarking standards
- Power consumption measurements
- Temperature testing results
- Code optimization documentation
- Library evaluation criteria
- Citation requirements for technical resources
- Integration with main code documentation

**Priority**: MEDIUM - Supports ongoing technical research

---

## Additional Recommendations

### For Documentation Repository (This Repo)

#### A. CONTRIBUTING.md (Root Level)

**File**: `CONTRIBUTING.md`

**Purpose**: Quick-start guide for all contributors

**Content:**
```markdown
# Contributing to StratoLab Documentation

Welcome! This repository contains educational documentation for the StratoLab
high-altitude balloon project.

## Quick Start

1. Read [Git Workflow Guidelines](.prompts/git-workflow.md)
2. Review [Documentation Standards](.prompts/documentation-standards.md)
3. Fork the repository and create a branch
4. Make your changes following the guidelines
5. Submit a pull request

## What Goes Here

- Lesson content and tutorials
- Hardware assembly guides
- Research documentation
- Materials lists and checklists
- Educational resources

## What Goes Elsewhere

- **Code**: Arduino/Python code → [telemetry repository](link-to-code-repo)
- **Issues**: General project issues → [main project issues](link)

## Getting Help

- Ask your mentor or teacher
- Create an issue for questions
- Join our [community discussions](link if available)

## Code of Conduct

This is an educational environment. Be respectful, patient, and supportive
of learners at all levels.

## License

All documentation is licensed under GPLv3. See [LICENSE](LICENSE) for details.
```

**Priority**: HIGH - First thing contributors see

---

#### B. Pull Request Template

**File**: `.github/PULL_REQUEST_TEMPLATE.md`

**Purpose**: Ensure consistent, complete PRs

**Content:**
```markdown
## Description

Brief description of what changed and why.

## Type of Change

- [ ] New lesson or major content addition
- [ ] Documentation fix or clarification
- [ ] Typo/grammar correction
- [ ] Image/asset update
- [ ] Content reorganization
- [ ] Other (please describe):

## Testing Checklist

- [ ] All links verified and working
- [ ] Images display correctly
- [ ] Markdown renders properly
- [ ] Content reviewed for spelling/grammar
- [ ] Code examples tested (if applicable)
- [ ] Hardware instructions verified (if applicable)

## Safety Review (if applicable)

- [ ] N/A - No safety-critical content
- [ ] Wiring diagrams verified against hardware
- [ ] Component specifications accurate
- [ ] Safety warnings included where needed
- [ ] Polarity/power warnings present

## Documentation Quality

- [ ] Follows lesson structure template (for lessons)
- [ ] Technical terms defined
- [ ] Alt text provided for all images
- [ ] Educational tone and style maintained
- [ ] Related content updated/cross-referenced

## Additional Notes

Any context reviewers should know? Related issues? Testing details?

## Screenshots (if visual changes)

Include before/after or relevant screenshots here.
```

**Priority**: HIGH - Improves PR quality

---

#### C. Issue Templates

**Directory**: `.github/ISSUE_TEMPLATE/`

Create templates for common issue types:

1. **documentation-error.md** - Corrections to existing documentation
2. **lesson-request.md** - Requests for new lesson content
3. **hardware-question.md** - Hardware-related questions
4. **general-question.md** - General questions

**Priority**: MEDIUM - Helps organize issues

---

#### D. README Updates

**File**: `README.md` (if exists) or `index.md`

**Updates Needed:**
- Add "Contributing" section linking to CONTRIBUTING.md
- Link to contribution guidelines in .prompts/
- Add section on code vs documentation repositories
- Include "How to Get Started Contributing" guide

**Priority**: MEDIUM - Improves discoverability

---

### For Code Repository

#### E. Code Repository CONTRIBUTING.md

**File**: `CONTRIBUTING.md` (in code repository)

**Purpose**: Guide code contributions

**Content:**
- Link to code quality and hardware contribution prompts
- Setup instructions for development environment
- Testing procedures for each platform (Pico, Arduino, ESP32)
- How to test with actual hardware
- Safety testing requirements
- Code review process
- Naming conventions for branches/commits

**Priority**: HIGH - Critical for code quality

---

#### F. Code PR Template

**File**: `.github/PULL_REQUEST_TEMPLATE.md` (in code repository)

**Content:**
- Hardware testing verification
- Power consumption measurements
- Temperature testing (if applicable)
- Safety review checklist
- Platform-specific testing (Pico/Arduino/ESP32)
- Documentation updates required
- Flight-ready certification

**Priority**: HIGH - Ensures tested code

---

## Implementation Priority Summary

### Immediate (This Repository)
1. ✅ `.prompts/git-workflow.md` - COMPLETED
2. ✅ `.prompts/documentation-standards.md` - COMPLETED
3. `CONTRIBUTING.md` - HIGH PRIORITY
4. `.github/PULL_REQUEST_TEMPLATE.md` - HIGH PRIORITY

### Near-term (Code Repository)
5. `.prompts/code-quality.md` - HIGH PRIORITY
6. `.prompts/hardware-contributions.md` - HIGH PRIORITY
7. `CONTRIBUTING.md` in code repo - HIGH PRIORITY
8. `.github/PULL_REQUEST_TEMPLATE.md` in code repo - HIGH PRIORITY

### As Needed
9. `.prompts/research-documentation.md` (code repo) - MEDIUM
10. Issue templates (both repos) - MEDIUM
11. README updates (both repos) - MEDIUM

---

## Notes

### Repository Separation Benefits

**Documentation Repository (this repo):**
- Focuses on educational content quality
- Lower barrier to entry for students
- Faster iteration on lessons
- Clear separation of concerns

**Code Repository:**
- Emphasizes testing and hardware validation
- Safety-critical review process
- Platform-specific standards
- Flight-ready certification

### Coordination Between Repositories

- Code changes often require documentation updates
- Cross-reference between repos in commit messages
- Maintain consistency in terminology
- Coordinate major releases

### Student Contribution Flow

1. **Learning Phase**: Students primarily contribute to documentation
   - Research findings
   - Lesson improvements
   - Troubleshooting additions

2. **Development Phase**: Advanced students contribute code
   - Tested on hardware
   - Reviewed by mentors
   - Documentation written in parallel

---

## Questions to Resolve

Before implementing remaining phases, consider:

1. What is the URL/location of the code repository?
2. Who maintains each repository (students, mentors, or both)?
3. Are there existing code standards to incorporate?
4. What testing infrastructure exists?
5. How are releases/versions coordinated?
6. Is there a formal code review process?

---

**Next Steps**:
1. Implement high-priority items for this repository (CONTRIBUTING.md, PR template)
2. Identify code repository location
3. Adapt Phase 2 prompts for code repository context
4. Establish cross-repo coordination workflow

---

*Last Updated: 2025-11-19*
*Maintainer: Project Leads/Mentors*
