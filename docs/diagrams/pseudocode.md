```
initialize sensor
set posture_threshold = 20 degrees

loop:
read angle
if angle > posture_threshold:
turn alert ON
else:
turn alert OFF
```
