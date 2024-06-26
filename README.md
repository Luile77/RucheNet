
# RucheNet: Intelligent monitoring and management of Saint Cyr bee colonies


## Summary 
The article "RucheNet: Intelligent monitoring and management of Saint Cyr bee colonies" looks at the use of an advanced system designed for real-time monitoring and management of bee colonies. The study assesses the impact of this innovative system on preventing Bee Colony Collapse Disorder (BCDS) and improving beekeeping productivity in Saint Cyr. Combining data collected through sensors installed on the hives and in-depth interviews with beekeepers, the aim is to measure the benefits of the system in terms of precision in monitoring vital parameters such as temperature, humidity and hive weight.


# Introduction
Faced with the ecological emergency represented by the global decline of bee populations, technological initiatives like "RucheNet" emerge as promising solutions to reverse this alarming trend. The project "RucheNet: Intelligent Surveillance and Management of Bee Colonies in Saint Cyr" is at the heart of this innovative approach, aiming to provide beekeepers with advanced monitoring and management tools for their hives.

The importance of bees in pollination, and by extension, in the preservation of biodiversity and food security is well documented. However, these essential pollinators are threatened by a multitude of factors, including diseases, parasites, the use of pesticides, climate changes, and habitat destruction. These threats, combined with the complexity of apicultural ecosystems, make traditional hive management both difficult and imprecise.

In response to these challenges, the "RucheNet" project proposes an integrated system of sensors and a real-time data platform to provide a precise and detailed overview of the health and activity of hives. This tool allows beekeepers in Saint Cyr to make informed and proactive decisions for the well-being of their colonies, thereby improving productivity and contributing to the sustainability of apiculture.

The project relies on collaboration between beekeepers and engineers to develop a solution that not only meets the specific needs of the hives in Saint Cyr but also serves as a model for similar initiatives in other regions. Through a participatory approach, "RucheNet" aims to equip the apicultural community with innovative tools to effectively face current and future threats, thus ensuring the sustainability of bee colonies and, by extension, the health of the ecosystems to which they are indispensable.

# The Importance of Bees in Ecosystems and Agriculture

Bees are key pollinating agents, essential for the reproduction of many wild plants and agricultural crops. Their role in pollination not only contributes to the biodiversity of ecosystems but also to global food security, with about one-third of food crops depending on insect pollination (Klein et al., 2007). This interdependence highlights the importance of maintaining healthy and robust bee populations.

Bees are facing multiple threats, including parasites like the Varroa Destructor, diseases, exposure to neonicotinoid pesticides, climate change, and habitat loss (Goulson et al., 2015). These factors contribute to colony collapse disorder, resulting in significant losses for beekeepers and jeopardizing the vital ecosystem services bees provide.

Recently, IoT technologies and sensor systems have increasingly been applied to apiculture, offering new possibilities for real-time monitoring of bee colonies. These systems allow tracking various parameters, such as temperature, humidity, hive weight, and bee activity, providing valuable data for proactive colony management (Fernandez-Carames et al., 2018). These tools represent significant potential to improve bee health and hive productivity.

Despite these advancements, many existing systems have limitations, including cost, complexity of use, and durability under harsh conditions. Furthermore, integrating collected data into practical management practices remains a challenge. The "RucheNet" project seeks to address these gaps by developing an integrated and accessible solution, specifically tailored to the needs of beekeepers in Saint Cyr. Through close collaboration between beekeepers and engineers, "RucheNet" aims to provide a robust and user-friendly platform for bee colony monitoring and management.

### References
- Klein, A.M., et al. (2007). *Importance of pollinators in changing landscapes for world crops*. Proceedings of the Royal Society B: Biological Sciences, 274(1608), 303-313.
- Goulson, D., et al. (2015). *Bee declines driven by combined stress from parasites, pesticides, and lack of flowers*. Science, 347(6229), 1255957.
- Fernandez-Carames, T.M., et al. (2018). *An IoT-based computational framework for healthcare monitoring in mobile environments*. Sensors, 18(10), 3269.


# Mission and Objectives

The mission of "RucheNet" is to provide an innovative, reliable platform for the real-time monitoring of beehives, catering to the urgent demands of beekeepers and researchers alike. At a time when environmental challenges are severely affecting bee populations, "RucheNet" stands as an indispensable resource. By meticulously tracking essential parameters such as temperature, humidity, hive weight, and ambient light exposure, the initiative does more than merely collect data; it opens a gateway to understanding the vitality and well-being of bee colonies. This, in turn, plays a pivotal role in enhancing global food security and conserving biodiversity.

# Technical Approach

"RucheNet" is grounded in a commitment to accuracy and dependability, leveraging state-of-the-art IoT technologies to ensure precise data collection and immediate delivery from beehives. By integrating a combination of carefully selected sensors with a resilient data transmission framework (LoRaWAN), "RucheNet" ensures that beekeepers and researchers are equipped with timely, actionable insights. This empowers them to make informed decisions that bolster the health and productivity of bee colonies. Furthermore, "RucheNet" incorporates advanced data analytics to interpret the collected data, providing a comprehensive view of each hive's status and highlighting potential issues before they become critical. This proactive approach to beehive management marks a significant advancement in apiculture, setting a new standard for technological interventions in the field.

## Hardware Details

### MKRWAN Board
- **Core Component**: The MKRWAN board, compatible with Arduino, serves as the heart of the "RucheNet" system. It's specifically designed for long-range LoRaWAN communication, making it ideal for transmitting data over vast distances without consuming excessive power.
- **Features**: The board's design focuses on compactness and efficiency, crucial for deploying within the constrained space of a beehive and ensuring minimal disturbance to the bees.

### DHT22 Temperature and Humidity Sensors
- **Accuracy**: These sensors are selected for their high precision in measuring temperature and humidity levels inside the hive. Such accurate data is vital for assessing the health of the colony and the impact of environmental conditions.
- **Reliability**: With a robust digital interface, the DHT22 ensures consistent performance, providing beekeepers with dependable data under a range of environmental conditions.

### DS18B20 Temperature Sensors
- **External Monitoring**: These sensors are tasked with monitoring the temperature outside the hive. Their high accuracy and efficiency in data communication via the OneWire protocol make them invaluable for understanding the external conditions affecting the hive.
- **Integration**: The DS18B20 sensors are easily integrated into the system, allowing for multiple units to share a single data line to minimize wiring complexity.

### H401-C3 Load Cell and HX711 Amplifier
- **Weight Tracking**: The combination of the H401-C3 load cell and the HX711 amplifier forms a potent system for monitoring hive weight with exceptional precision. This metric is crucial for tracking honey production and the overall activity level within the hive.
- **Data Quality**: The HX711 amplifier enhances the signal quality from the load cell, ensuring noise-free, accurate weight data crucial for effective hive management.

### Photoresistor
- **Light Sensing**: The inclusion of a photoresistor allows the system to measure ambient light levels. This information is vital for analyzing how external light conditions impact bee activity and hive dynamics.

### Buzzer
- **Auditory Alerts**: The buzzer provides an immediate auditory response to certain conditions or alerts specified by the system, such as significant temperature changes or weight fluctuations. This feature facilitates prompt action from the beekeeper.

### Power Supply: LiPo Battery and Solar Panels
- **Sustainability**: A rechargeable LiPo battery powers the system, emphasizing the project's commitment to energy efficiency and sustainability. Solar panels support the battery, ensuring that the system remains operational through renewable energy.

### TPL5110 Power Management Module
- This module significantly enhances the system's energy efficiency. By regulating the power supplied to the sensors and the MKRWAN board, it ensures that the system consumes power only when necessary, extending the operational lifespan of the battery.

## PCB Schematic
PCB Schematic At the heart of the project lies the PCB, which seamlessly integrates all hardware components to ensure smooth communication and functionality. It boasts dedicated connectors for the MKRWAN 1310, interfaces for an array of sensors, and the TPL5110 module for power management. Meticulously designed, the layout of the PCB accommodates the system's requirements, offering a reliable and efficient platform for the Open Ruche monitoring system.

**Key Features:** MKRWAN 1310 Interface: The PCB features a dedicated interface for effortless connection with the MKRWAN 1310 board, ensuring compatibility and efficient data transmission.

**Sensor Connections:** Accommodating multiple sensors, the PCB allows for the collection of crucial data. Detailed interfaces for each sensor type are provided, enabling precise measurements.

**TPL5110 Integration:** The PCB seamlessly integrates the TPL5110 module to enhance power management and optimize energy consumption, contributing to the project's low-power operation.

![PCB](https://i.imgur.com/5JQnaoT.jpeg)
![PCB2](https://i.imgur.com/4gsJzIF.jpeg)

## Software Requirements

1.  **Arduino IDE:** The Arduino Integrated Development Environment (IDE) serves as the primary software tool for programming and uploading code to the MKRWAN board. It offers a user-friendly interface and supports various programming languages such as C and C++. Additionally, the Arduino IDE provides access to a vast library of pre-built functions and examples, simplifying the development process for the MKRWAN board. Ensure that the necessary libraries for LoRaWAN communication and sensor interfacing are installed within the Arduino IDE environment.
    
2.  **LoRaWAN Connectivity Setup:** To establish LoRaWAN connectivity, you need to configure the MKRWAN board to communicate with a LoRaWAN network server. This involves setting parameters such as device address, network session key, and application session key, which are provided by your chosen network provider (e.g., The Things Network - TTN). Additionally, you may need to configure regional parameters such as frequency bands and data rates to ensure compatibility with your target deployment region. Once configured, the MKRWAN board can transmit and receive data packets over the LoRaWAN network, enabling long-range wireless communication for your monitoring system.

Beep Application Interface

Open Ruche seamlessly integrates with the Beep application to provide a clear and user-friendly visualization of the collected hive data. The Beep interface, as depicted in the screenshot below, presents detailed graphs and analytics generated from various parameters monitored within the hive:

![Beep](https://i.imgur.com/4FfOHgY.jpeg)
This intuitive interface empowers beekeepers and researchers to monitor crucial parameters such as temperature, humidity, hive weight, and light exposure. Through interactive graphs and analytics, users gain valuable insights, facilitating informed decision-making for effective hive management.

The Open Ruche system transmits data to the Beep platform via The Things Network (TTN), enabling comprehensive visualization and analysis of the beehive's conditions. To ensure seamless data transmission and proper formatting, follow the steps outlined below:

1. **TTN Integration**: Configure the Open Ruche system to transmit data to The Things Network (TTN). Set up TTN with appropriate device registration and application configuration.

2. **Data Formatting**: Ensure that the data transmitted from Open Ruche to TTN is properly formatted according to Beep's specifications. This includes structuring the payload to include relevant sensor readings and metadata.

3. **TTN Integration with Beep**: Configure TTN to forward the collected data to the Beep application. Utilize TTN's integration features to seamlessly relay data to Beep for visualization and analysis.

By following these steps, you can establish a robust connection between Open Ruche and the Beep application, enabling real-time monitoring and insightful analysis of hive conditions for improved beekeeping practices.

# Acknowledgements
This project is a collaborative effort by students at Polytech Sorbonne: Myriem Hajmi, Louis LE, Issam Bouhali
 
# Contact
For more information or inquiries, please contact us.

