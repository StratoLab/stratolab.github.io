# Interactive Site Implementation Plan

This document outlines the plan for converting the StratoLab documentation from static GitHub Pages (Jekyll-based Markdown rendering) to a dynamic single-page application (SPA) that provides better navigation, track filtering, and user experience.

## Goals

1. **Track-based navigation** - Allow users to filter content by microcontroller platform (Pico, Arduino, ESP32)
2. **Persistent progress** - Remember where users left off and offer to continue
3. **Quick reference tools** - Provide easy access to pinout diagrams and other frequently-needed references
4. **Mobile-friendly** - Responsive design with hamburger menu for smaller screens
5. **No build step** - Keep deployment simple (static files, no Node.js/Jekyll build required)
6. **Accessibility** - ARIA labels, keyboard navigation, semantic HTML

---

## Architecture

### Core Files

| File | Purpose |
|------|---------|
| `index.html` | Single-page application shell with embedded JavaScript |
| `style.css` | All styling including responsive breakpoints |
| `site-config.json` | Navigation structure, track definitions, content paths |
| `serve.sh` | Local development server script |

### How It Works

1. **On load**: Fetch `site-config.json` to build navigation tree
2. **Track picker**: Filter sidebar to show only selected track's content
3. **Content loading**: Fetch Markdown files, parse with marked.js, inject into `#content`
4. **URL hashing**: Use `#section-id` for deep linking and browser history
5. **localStorage**: Save last visited page for "continue where you left off" feature

---

## Implementation Phases

### Phase 1: Core SPA Shell (COMPLETED)

- [x] Create `index.html` with header, sidebar, and content areas
- [x] Create `site-config.json` with all navigation items
- [x] Create `style.css` with full styling
- [x] Implement track picker (All, Pico, Arduino, ESP32)
- [x] Implement sidebar navigation tree
- [x] Implement collapsible groups (Balloon section)
- [x] Implement Markdown fetching and rendering with marked.js
- [x] Implement relative path rewriting for images/links
- [x] Implement URL hash-based routing
- [x] Implement "continue where you left off" toast
- [x] Implement mobile responsive design with hamburger menu
- [x] Implement landing page content
- [x] Add stub handling for "coming soon" lessons
- [x] Add local development server (`serve.sh`)
- [x] Update CONTRIBUTING.md with local development instructions

### Phase 1.5: Quick Reference Tools (COMPLETED)

- [x] Add floating action button (FAB) for Pico pinout
- [x] Create pinout modal with full-size diagram
- [x] FAB only visible when viewing Pico track content
- [x] Add pinout thumbnail image
- [x] Keyboard accessible (Escape to close modal)

### Phase 2: Search (PLANNED)

- [ ] Add search input to header (replace `#search-placeholder`)
- [ ] Build search index from `site-config.json` titles
- [ ] Implement client-side fuzzy search
- [ ] Show search results dropdown
- [ ] Navigate to result on selection
- [ ] Keyboard navigation for search results (arrow keys, Enter)

**Design considerations:**
- Keep it simple - search titles only, not full content
- No external dependencies (no Algolia, Lunr.js, etc.)
- Could expand to content search in Phase 3 if needed

### Phase 3: Enhanced Features (PLANNED)

- [ ] Progress tracking across lessons (checkmarks for completed)
- [ ] Expand quick reference to Arduino/ESP32 pinouts
- [ ] Print-friendly styles for individual lessons
- [ ] Table of contents for long lessons (auto-generated from headings)
- [ ] Dark mode toggle
- [ ] Code syntax highlighting (consider Prism.js or highlight.js)

### Phase 4: Content Improvements (PLANNED)

- [ ] Review and update all lesson content for consistency
- [ ] Ensure all images have proper alt text
- [ ] Add missing troubleshooting sections
- [ ] Verify all external links work
- [ ] Add more cross-references between related lessons

---

## Site Configuration Schema

The `site-config.json` file defines the navigation structure:

```json
{
  "shared": [
    {
      "id": "unique-id",
      "title": "Display Title",
      "path": "path/to/file.md"
    },
    {
      "id": "group-id",
      "title": "Group Title",
      "collapsed": true,
      "children": [
        { "id": "child-id", "title": "Child", "path": "path.md" }
      ]
    }
  ],
  "tracks": [
    {
      "id": "track-id",
      "title": "Track Title",
      "sections": [
        { "id": "section-id", "title": "Section", "path": "path.md" },
        { "id": "stub-id", "title": "Coming Soon", "path": "path.md", "stub": true }
      ]
    }
  ]
}
```

### Fields

- `id`: Unique identifier, used in URL hash (e.g., `#pico-lesson-1`)
- `title`: Display text in navigation
- `path`: Relative path to Markdown file
- `collapsed`: (optional) Start group collapsed in sidebar
- `stub`: (optional) Mark as "coming soon" - won't load content
- `children`: (optional) Nested navigation items

---

## File Structure

```
stratolab.github.io/
├── index.html              # SPA shell
├── style.css               # Styles
├── site-config.json        # Navigation config
├── serve.sh                # Local dev server
├── assets/
│   └── images/
│       ├── stratolab.svg   # Logo
│       └── pinouts/
│           ├── raspberry-pi-pico-pinout.png
│           └── raspberry-pi-pico-pinout-thumb.png
├── materials.md            # Shared content
├── initial-research.md
├── resources.md
├── balloon/                # Balloon docs
│   ├── overview.md
│   ├── supplies.md
│   ├── assembly.md
│   ├── prediction.md
│   └── checklist.md
└── telemetry/              # Track-specific lessons
    ├── raspberry-pi-pico/
    ├── arduino/
    └── esp32-heltec-tracker/
```

---

## Testing Checklist

Before deploying changes:

- [ ] Run local server (`./serve.sh`) and verify all navigation works
- [ ] Test track picker filtering
- [ ] Test deep links (e.g., `index.html#pico-lesson-3`)
- [ ] Test "continue where you left off" toast
- [ ] Test mobile view (hamburger menu, sidebar overlay)
- [ ] Test keyboard navigation (Tab, Enter, Escape)
- [ ] Verify images load correctly in lessons
- [ ] Test stub/"coming soon" items
- [ ] Check browser console for errors

---

## Notes

- **No Jekyll**: This replaces Jekyll with client-side Markdown rendering
- **marked.js**: Loaded from CDN for Markdown parsing
- **Browser support**: Modern browsers only (uses fetch, async/await, CSS custom properties)
- **Accessibility**: Screen reader tested with NVDA/VoiceOver

---

*Last updated: February 2026*
