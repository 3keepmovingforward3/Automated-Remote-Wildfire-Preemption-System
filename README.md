# Automated-Remote-Wildfire-Preemption-System
Automated reporting of wildfire to governments as preventative life and property saving measures reducing harm

Inspiration
The Benjamin Franklin axiom that “an ounce of prevention is worth a pound of cure” is as true today as it was when Franklin made the quote. Although many use the quote when referring to health, Franklin actually was addressing fire safety. Wildfires destroy the lives of families, friends, businesses, nature, the environment, all cruelly lost for lack of preventional mitigation. Some examples below show what can happen when environmental control is lost:

The 2018 wildfire season was the deadliest and most destructive wildfire season on record in California

With a total of 8,527 fires burning an area of 1,893,913 acres (766,439 ha), the largest amount of burned acreage recorded in a fire season, according to the California Department of Forestry and Fire Protection (Cal Fire) and the National Interagency Fire Center (NIFC), as of December 21. The fires have caused more than $3.5 billion (2018 USD) in damages, including $1.792 billion in fire suppression costs. Through the end of August 2018, Cal Fire alone spent $432 million on operations.
The Mendocino Complex Fire fires collectively destroyed 280 structures while damaging 37 others;[1] causing at least $267 million (2018 USD) in damages, including $56 million in insured property damage and $201 million (2018 USD) in fire suppression costs. One firefighter died in these wildfires.

The Camp Fire wildfire in California burned for 17 days, caused at least 85 civilian fatalities, with 3 persons still missing, and injured 12 civilians, two prison inmate firefighters, and three other firefighters. It covered an area of 153,336 acres (62,053 ha) (almost 240 sq. miles), and destroyed 18,804 structures, with most of the damage occurring within the first four hours. Total damage was $16.5 billion; one-quarter of the damage, $4 billion, was not insured. The fire reached 100 percent containment after seventeen days on November 25, 2018.

Fatalities
On June 4, the Panoche Fire broke out, in a series of three blazes that started in the San Benito County area. While the Panoche incident was the smallest of the three fires, burning only 64 acres (26 ha), the remains of three people were found in a destroyed camping trailer in the burn area. The remains were believed to belong to a mother, a toddler, and an infant.

On July 14, a Cal Fire bulldozer operator was killed while fighting the Ferguson Fire, becoming the first firefighter death of the season.

On July 23, the Carr Fire broke out after a vehicle malfunctioned. While the Carr Fire burned in rural areas of Shasta County for the first few days, it crossed the Sacramento River and entered the city limits of Redding, California on the evening of July 26. By the next morning, two firefighters and four civilians had been killed.

On July 29, a firefighter with the National Park Service was killed after a dead tree fell and struck him, while he was fighting the Ferguson Fire. He was "treated on scene, but died before he could be taken to the hospital".

On August 4, a Pacific Gas and Electric Company employee was killed in a vehicle incident while working to restore services to areas impacted by the Carr Fire.

On August 9, a Cal Fire heavy equipment mechanic was killed in a traffic incident while working at the Carr Fire.

On August 13, a firefighter was killed while fighting the Mendocino Complex Fire.

On November 9, 2018, at least 88 civilians were killed by the Camp Fire, while three firefighters were injured, the fire also destroyed more than 10,321 structures, becoming the deadliest and most destructive fire in California history. Three people also died during the Woolsey Fire near Malibu. The number dead was lowered to 85 by early December when it was discovered one victim was put in several bags.

What it does
Automated Remote Wildfire Preemption System consists of multiple sensors that will be sensing the temperature and IR, and once it goes above the threshold value that we set (which can be varied) the sensor will sense the temperature and send the signals to the assembled Arduino/DragonBoard 410c. The data from the board is then sent to the XPT-2046 5" LCD which has a program written in python checking whether the sensed value is above the set threshold or not. If YES, then the device will send the signal to a remote server which notifies authorities that there is wildfire that is happening and this data will be provided to the public and the fire department as well with the help of the call for which we did make use of Twilio API services, and if it’s below the threshold we will ignore it .

How we built it
We started by finding the array of sensors we could use to simulate real-world sensing equipment. We created a small logic circuit and connected it to the Arduino breakout board. We programmed the Arduino through the DragonBoard 401c board, The DragonBoard has a modified Linux Kernel, which required research into Linaro kernel system functions, as well as installing the appropriate Python3 packages for later use. We SSH'd into the DragonBoard as a test to identify the networking constraints. In parallel, we wrote simple programs in Python3 whilst setting up a Twilio upgraded account which cost $20. This allowed us to create a custom automated message. We then set-up the correct Python3 method calls to invoke the Twilio XML document to use text-to-speech. Finally, we used programming control logic to determine when a "wildfire" condition is present. This requires both inputs, temperature, and IR, to be above minimum threshold values simultaneously to invoke the Twilio API call. The call invokes an XML document with custom API calls to do speech to text. We tailored the message to California Wildfire reporting requirements.

Challenges we ran into
First, we were not sure how can we put the data from the Breadboard to DragonBoard. Then getting the data from the DragonBoard to the server was another challenge. The DragonBoard has the specialized version of Linux, but we did figure out the nuances after some time.

Accomplishments that we're proud of
The project that we have made is very cheap. Wildfire fire is a crucial issue and according to the stats, the recent wildfires that took place in 2018 resulted in the damage of 3.5 billion. Which is a very huge loss. We are very proud that we are providing a solution to a problem which is very crucial and that too in a very less cost (approximately 1000$, if we make use more of more advanced sensors rather than the sensors that were been provided) as compared to the damage that has been done by the wildfire. Making use of low-cost components, each square mile of California could have around 21 kits helping to prevent loss of life.

What we learned
We learned how to get the data from the sensors to the DragonBoard. We learned how to make use of DragonBoard 410c, which we haven’t used before. Interfacing between DragonBoard and server. Used Twilio API services for the first time.

What's next for Automated Remote Wildfire Preemption System
We did this project work for providing awareness to the people and to the fire department but further, we want to spread the awareness on social media as well. Now, why to make spread it on social media if you are already calling. The reason behind this is, people sometimes ignore calls from unknown numbers, or if they are at work, they’re not able to pick up the call. So, in order to make people aware of the same we are thinking of leveraging social media platforms as well, so even if they miss the call they will be notified through social media. We would like to make use of more advanced sensors so that maximum area would be covered using a single kit.
