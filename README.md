# Smart-shopping-IoT

## Overview
The Smart Shopping Cart is an innovative project that aims to streamline the checkout process in stores using Arduino and RFID technology. This system not only speeds up the checkout process but also ensures accurate billing and enhances the overall shopping experience.

## Features
- **Reduce checkout time and queues:** Eliminates the need for human cashiers, resulting in shorter lines and a faster checkout process.
- **Enhance customer experience:** Allows customers to shop at their own pace with real-time updates on the total cost of their purchases.
- **Reduce errors and improve accuracy:** Automated system ensures accurate billing and prevents overcharges.
- **Improve data collection and analytics:** Generates valuable data on customer behavior and product trends.
- **Enable mobile payment options:** Supports payments via smartphones or mobile wallets.
- **Reduce inventory management costs:** Tracks product movement to optimize inventory management.

## Goals
1. Encourage impulse purchases.
2. Empower personalized shopping experiences.
3. Enable self-checkout at smaller stores.
4. Reduce operational costs.
5. Facilitate data-driven decision-making.

## Solution
Integrating Arduino and RFID technology, each item in the store carries a unique RFID tag. The smart cart accurately identifies and tracks these items as they are scanned, automatically updating the total amount. This automated system expedites checkout and ensures accurate pricing. Additionally, the smart cart can provide product information and recommendations, enhancing the shopping experience.

## Methodology
1. **Identify RFID codes:** Each RFID card has a unique 12-digit code that must be known beforehand.
2. **Code Development:** Write the code to add products to bills and handle deletion of all products from the bill.
3. **RFID Cards:** Use 5 RFID cards and 1 RFID tag. One card deletes all products, and the tag generates the bill.
4. **Circuit Connection:** Connect the circuit, upload the code to the Arduino, and use a laptop display as the output stream.

## Project Requirements
| Description           | Quantity |
|-----------------------|----------|
| Arduino Nano          | 1        |
| RFID Scanner (RC522)  | 1        |
| RFID Cards            | 6        |
| RFID Tag              | 1        |
| Jumper Wires          | 15       |
| Arduino USB Cable     | 1        |
| **Total**             | **25**   |


## Contributors
- Akshat Vaja 
- Aarya Gopani 

## License
This project is licensed under the MIT License.
