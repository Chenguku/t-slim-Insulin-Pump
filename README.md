# t-slim-Insulin-Pump

Team 14: \
Stanley Huang \
Jason Li \
Methira Herath \
Daniel Yang

## Build Instructions
The QCharts module for Qt 5 is required for this project to build. It can be downloaded on Ubuntu using the following command: \
``` sudo apt install libqt5charts5-dev ```

## Use notes 
- A profile must be set to active before basal insulin delivery can occur
- Manual bolus and bolus automatically administered by CGM when blood glucose is greater than 10mmol/L will occur regardless of if a profile is set

## Design Documentation:

| Design Document   | Created by:   |
|-------------------|---------------|
| Use Cases         | Jason Li      | 
| Sequence Diagrams | Daniel Yang   |
| Use Case Diagram  | Stanley Huang |
| State Machine Diagrams  | Stanley Huang |
| UML Diagram | Methira Herath |
| Requirements Traceability Matrix | Jason Li |
| Demo Video | Daniel Yang |

## Feature Implementation:

| Feature      | Contributors: |
|--------------|---------------|
| Power On     | Stanley Huang |
| Lock Screen  | Stanley Huang |
| Home Screen  | Jason Li      |
| Profile Management | Methira Herath |
| Manual Bolus Delivery | Daniel Yang |
| Continuous Glucose Monitoring | Jason Li |
| Basal Insulin Delivery | Jason Li |
| Pump Information and History | Stanley Huang |


## Class Implementation:

| Class           | Contributors:                        |
|-----------------|--------------------------------------|
| BolusCalculator | Daniel Yang                          |
| CGM             | Daniel Yang, Jason Li                |
| MainWindow      | Stanley Huang, Jason Li, Daniel Yang, Methira Herath |
| Profile         | Methira Herath |
| InsulinDeliveryProfile | Methira Herath, Daniel Yang |
| Event | Stanley Huang |
| EventHistory | Stanley Huang | 
| GlucoseReader_Mock | Jason Li |
| ProfileFormWidget | Methira Herath |
| ProfilesPageWidget | Methira Herath |
