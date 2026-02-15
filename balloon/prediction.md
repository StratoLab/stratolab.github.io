

# Predicting Balloon Flight

## Burst Calculations

[SondeHub Burst Calculation Website](https://sondehub.org/calc/)

- Modify the fields with a red star for your needs:
  - Payload Mass is the weight of everything below the balloon you will be flying in grams. A simple [Google search](https://www.google.com/search?q=pounds+to+grams&oq=pounds+to+gram&aqs=chrome.0.35i39j69i57j0i512l8.4770j0j7&sourceid=chrome&ie=UTF-8) will yield the conversions
    - Rigging line(s), parachute, payload harness, Payload nd contents, and anything attached to the payload
  - Ballon Mass is the size balloon you will be flying. Be sure to select the proper size AND manufacturer. It's not a bad idea to validate the specs as we found the burst diameter a bit off.
  - Target Ascent rate in meters per second
    - For best camera results an ascent of 6 meters per second is optimal but you will likely need a different rate based on your lift gas volume
      - A flow gauge can be used to dial in the right amount of gas but they are typically cost prohibitive. These gauges are typically different for each type of gas as well.
    - You will need to modify this until the volume changes to your lift gas tank volume. A simple [Google search](https://www.google.com/search?q=cubic+feet+to+meters&sxsrf=APwXEdcz7Z9132iZwT_5k74WRE1ANWrVwA%3A1682485057227&ei=Qa9IZLvEDf-iptQP4aqroAg&ved=0ahUKEwj76LOh4cb-AhV_kYkEHWHVCoQQ4dUDCBA&uact=5&oq=cubic+feet+to+meters&gs_lcp=Cgxnd3Mtd2l6LXNlcnAQAzIFCAAQgAQyBQgAEIAEMgUIABCABDIFCAAQgAQyBggAEBYQHjIICAAQFhAeEA8yBggAEBYQHjIGCAAQFhAeMgYIABAWEB4yBggAEBYQHjoECCMQJzoHCAAQigUQQzoKCAAQigUQsQMQQzoNCC4QigUQsQMQgwEQQzoLCAAQgAQQsQMQgwE6CAgAEIoFEJECOgsIABCKBRCxAxCRAkoECEEYAFAAWP0kYKInaABwAXgAgAHIAYgB0BKSAQYxLjE4LjGYAQCgAQHAAQE&sclient=gws-wiz-serp) can convert m3 to cubic feet
   - Gas needs to be changed ot the lift gas you will be using. The calculations will be different for each lift gas option!


![SonceHub_Burst_image](assets/images/sondehub_burst.png)

## Landing Prediction Calculator

[Sonde HAB Prediction Calculator](https://predict.sondehub.org/)

- Modify the fields with a red star for your needs:
  - Latitude and Longitude
    - You can use many tools like [maps.google.com](maps.google.com)
      - Find the location best suited for winds at launch time and place a waypoint. The latitude and longitude will be shown or copied easily from the shared link
  - Launch Altitude
    - THis can be determined with many tools like Google Earth, USGS, [websites](https://whatismyelevation.com/), etc
      - Be sure to convert to meters
  - Launch time UTC
    - [Convert](https://www.google.com/search?q=what+time+is+it+utc&oq=What+time+is+it+utc&aqs=chrome.0.35i39j0i512l9.2977j0j7&sourceid=chrome&ie=UTF-8) local time to UTC
- Launch Date
- Ascent Rate (m)
  - This was claculated fromt he above instructions on [SondeHub Burst Calculation Website](https://sondehub.org/calc/)
- Burst/Float Altitude (m)
  - This was claculated fromt he above instructions on [SondeHub Burst Calculation Website](https://sondehub.org/calc/)
- Descent Rate (m/s)
  - this will be defined by your parachute. Be sure you calculate based on the adjustments on your actual parachute as many can be reduced

![SonceHub_Burst_image](assets/images/sonde_prediction.png)
