.. _designPatterns:

Design Patterns
===============


Behavioral Design Pattern - Mediator
------------------------------------

The behavioral design pattern is shown in the figure below.

.. uml:: ../../../resources/designPatterns/behavioral.uml
    :caption: Behavioral Design Pattern - Mediator.
    :align: center

The pattern here centralizes all sparse matrix types around the ELLPACK type. 
The user input will be automatically converted to the ELLPACK type for all calculations.
After the matrix vector multiplication is performed on the ELLPACK type, the matrix will be converted back into the desired output type.
This Mediator pattern was chosen as ELLPACK acts as a mediator for all other sparse matrix types.
Each sparse matrix type depends solely on the single mediator ELLPACK class rather than being fully coupled. 

Creational Design Pattern
-------------------------

The creational design pattern is shown in the image below.

.. uml:: ../../../resources/designPatterns/creational.uml
    :caption: Creational Design Pattern.
    :align: center

.. note::

    This creational pattern closely mirrors the UML class diagram.

Structural Design Pattern
-------------------------

The structural design pattern is shown in the image below.

.. uml:: ../../../resources/designPatterns/structural.uml
    :caption: Structural Design Pattern - Facade.
    :align: center

This pattern demonstrates the interactions between the client and the facade class that provides the interface for the user.
The facade pattern was chosen as it is the most fitting for the SpMV library.
The user has access to the three inputs: matrix, matrix data type, and sparse matrix type.
At this point, the user no longer needs access to the methods and attributes of the SpMV class as the process is handled by the library.
