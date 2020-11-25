# Classic Car Operating System
<p>(karOs, based on my classic 1972 VW Karmann Ghia)</p>
<h1>Goal of Project</h1>
<p>Project is meant to serve as a base for processing a variety of tasks on vehicles built prior to the computer age.
As the goal of any computing is to process input and output, the basic goal will be to send and receive 12 volt signals between
the car and the computer, in this case ESP32.</p>
<h1>Hardware</h1>
<p>Hardware will be centered around the ESP32 microcontroller and will handle communication to a variety of peripheral boards</p>
<ul>
  <li>2.2 inch LCD Touch Display</li>
  <li>8-Relay Circuit Shield</li>
  <li>Opto isolation 5v to 12v board</li>
  <li>Opto isolation 12v to 5v board</li>
</ul>
<h1>Code</h1>
<p>Code will work through the integration of all hardware specified above.  Current step is integration into LCD Touch Display.  Display will be used to show all values
from the input pins and the status of all outputs, specifically one's that have activated a peripheral shield.</p>
