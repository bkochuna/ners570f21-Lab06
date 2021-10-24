.. _umlDiagram:

UML Diagram
===========

The structure of the SpMV library is documented using the Unified Modeling Language (UML).
Several UML diagrams are included below showcasing the classes, the abstract factory, the builder pattern, and an example state diagram.

Class Diagram
-------------

The class diagram showing the class hierarchy as well as attributes and methods for each level class is shown in the figure below.

.. uml:: ../../../resources/umlDiagrams/classDiagram.uml
    :caption: Class hierarchy UML diagram.
    :align: center

For SpMV, the abstract class is ``SparseMatrix``, which contains extensions to the associated concrete classes for each sparse matrix format.
The sparse matrix format that will be used for computation is ELLPACK, so each concrete object is a composition of itself with an instance of the ``SparseMatrixELLPACK`` concrete class.
This centralized class is useful for minimizing code duplication and redundancy.
The abstract class contains several common attributes and methods that are inherited by the concrete classes, while each concrete class houses its own individual attributes and methods.

Abstract Factory
----------------

The Abstract Factory structure used in SpMV provides an interface for creating families of related or dependent objects without their concrete classes.
The Abstract Factory design for SpMV is shown in the figure below.

.. uml:: ../../../resources/umlDiagrams/abstractFactory.uml
    :caption: Abstract factory UML diagram.
    :align: center

In the abstract factory, a client initializes a sparse matrix object using the ``SparseMatrixFactory`` interface.
This interface will call one of several concrete classes to generate a sparse matrix in the desired form.
The interface provides the client link to a sparse matrix object that the client can use without direct interaction with many of the methods within the dependent classes.

The COO implementation is in the ``coo.hpp`` file and the CRS is in ``crs.hpp`` file currently located in the ``src`` directory.
.. TODO add in where the BCRS, ELLPACK, and JDS implementations are.
They are basic functions written in C that create the sparse matrix formats.

Builder Pattern
---------------

Initializing and setting up a sparse matrix within SpMV requires several steps to properly define all of the required parameters.
A builder pattern for a client generating a sparse matrix is shown below.

.. uml:: ../../../resources/umlDiagrams/builderPattern.uml
    :caption: Builder pattern UML diagram.
    :align: center

In this builder pattern, once a client has initialized a sparse matrix it can call this matrix to set the coefficients within it.
This is done with repeated calls to the ``setCoefficients`` method.
Once the spares matrix is set, it can be assembled and stored in the desired format.
This assembly results in a fully initialized ``ConcreteSparseMatrix`` object instance that can be used for computation.

State Diagram
---------------

Below is an example of the state diagram for building a matrix within SpMV, setting the coefficients, assembling it, and then obtaining the format.
This diagram is only an example and can and should be expanded for other use cases.

.. uml:: ../../../resources/umlDiagrams/stateDiagram.uml
    :caption: State Diagram UML diagram.
    :align: center
