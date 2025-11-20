# Goals

- Students will learn to think systematically to solve problems which is the core of learning how to program
- Use resources available to solve problems
- Work as a small group to spread the work
- Present the research in the December session

## Plan

Below are topics to be assigned to small groups in the classrooms. The small group will need to research details and evaluate where problems may arise and how to proactively solve them. Mentors can help facilitate if students get stuck! Each sub section is one per group to be assigned by the teacher / lead mentor.

- The main topics below can be assigned across small groups of students in a classroom.
  - Distribute the topics across teams as needed. These teams will persist throughout the project.
  - If the lead mentor can report back which mentor has what topics that would be helpful
- Teams are welcome to explore the topic beyond the thought starters listed
- Research will be needed, use ALL resources available to research as a team (cell phones, laptops, etc. to search the internet). These topics should EASILY fill the class period with discussion
- Each team is to present in December their findings / solutions to the issues they were assigned
  - It is at the teacher's discretion how they present to the class (open discussion, PowerPoints, etc.)
  - The December session will be spend doing the share out taking the entire class time
    - Teams will need to be prepared BEFORE the December session; no time will be provided in the December session for prep

### Temperature issues

  - The balloon will travel to 110,000 feet. What temperatures will it encounter through the flight column
  - What temperature limitations would an Arduino UNO, Raspberry PICO, rechargeable battery, etc have?
  - Reverse, what would high temperature limitations be?
  - How can things be tested on the ground?
  - How to protect things thermally?
  - Will anything used produce heat?

### Power / Battery issues

  - Some assumptions / constraints

    - Average flight time is 4 hours
    - Research average temperatures in the upper atmosphere
    - [An AA size dry cell has a capacity of about 2,000 to 3,000 milliampere hours](https://en.wikipedia.org/wiki/Ampere_hour)
    - We need to be around 4lbs total for our payload EVERYTHING included below the balloon (weight is a BIG concern)
  - What kinds of batteries can we use and the pros and cons of each (rechargeable (different kinds), dry cell, battery size, weight)
  - How much capacity is needed for the flight running the following items:
    - 3 Action Cameras
      - 600 [mAh](https://en.wikipedia.org/wiki/Ampere_hour) per camera per hour of recording
    - One Arduino Uno
      - The Arduino Uno board draws about 42 mA assuming no power draw from sensors or other components needed in your system. With a minimum supply voltage of 7 volts, the power consumption of the board is therefore 0.29 Watts
    - [Tracker](http://qrp-labs.com/lightaprsw2)
      - Assume same power as Arduino
  - Any other items of note to share from your research or further questions?

### Tracking

  - How can we track the balloon in flight?
    - Telemetry broadcasting of extra sensors is a plus, at a minimum we need latitude, longitude, and altitude near real time
    - Need for recovery of the payload
      - Video
      - Electronics
  - Pros and cons of each solution researched?
    - Many items should be accounted for like is it legal, does it need to face a certain direction, does it need a clear line of sight to the sky, power needs, weight, etc.
    - Is there a way to record the flight data for retrieval later for each option?
    - How would we mount it in the foam cooler (12"x12"x12")
    - Can there be backup tracking options?
  - Any other items of note to share from your research or further questions?

### Laws, regulations, and safety

  - What laws and regulations are we restricted to by the FAA?
    - Payload weight
    - Rigging cords
    - Notifications
  - Who would we notify of our flight? (NOTAMs (Notices to Air Missions) via the FAA's Federal NOTAM System)
  - What threats could influence the safety of a flight and how might the risk be eliminated or mitigated?
  - Any other items of note to share from your research or further questions?

### Cameras

  - What area should be recorded during the flight and why
  - What kind of camera should we use
    - Power usage, weight, orientation, weather resistant or easy way to make it weather proof, etc
    - What is the operating temperature range
    - Pros and cons of each solution researched?
  - Will there be a problem with [RFI](https://en.wikipedia.org/wiki/Radio_frequency)? What measures can be taken to prevent issues with RFI?
  - How to mount them in the foam cooler (12"x12"x12")
  - Any other items of note to share from your research or further questions?

### Payload stabilization and rigging

  - How to retrieve if caught in a tree, roof, other obstruction
  - How do we keep the balloon from spinning too much?
  - Tangle hazards that would prevent the parachute from working
  - Proposed methods to attach the balloon to the payload?
    - Assumption is the payload is a foam cooler (12"x12"x12")
  - Any other items of note to share from your research or further questions?

### Landing prediction

  - How can we plan for approximate landing location of the HAB
  - What factors impact or go into the prediction
  - When should the prediction be run
  - Any other items of note to share from your research or further questions?

### Lift gas

  - Options for lift gas in our balloon
    - Safety concerns, availability, cost, where to buy, quality, regulations
    - Pros and cons
  - How much do we need for a [1600 gram balloon](https://www.kaymont.com/_files/ugd/a13aac_8b84755b308c473b8ac99f1dc39b80e1.pdf) carrying a 4lb payload
  - How do we know how much gas we dispensed from the tank
  - Any other items of note to share from your research or further questions?