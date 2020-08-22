<h3>CS210-Programming-Languages</h3>
<h/4> Zoo Animals Database </h4>

This project was for my computer science class and was my first course in C++.  This program integrated Java and C++
together to create a database that kept track of zoo animals.  The premise of the project was that each animal would
have a tracking device and the software that I was prototyping would have to interface with the tracking devices to 
record data on the animals.  That is why Java and C++ needed to be integrated together for this project.  What I think
I did particularly well was following the UML diagram given to me the accompanying materials for the software specifications.
I likely would have used Animal Class data members for different type and subtypes of animals instead of using classes.  
By following the UML, I learned a lot about virtual functions (polymorphism), inheritance and pointers.  Since I had to keep
all animals in a single vector, the solution I came up with was to use the base class Animal pointers to point to derived class
objects such as whales or crocodiles.  I have recently learned of function and class templates (which were not a part of my course)
and I wonder if that could have been another possible route to take to create the desired data.  

My code could definitely be enhanced.  My code looks as if I am trying to write Java code in C++.  I constantly forget to use pass 
by reference to change variable values and my entire InputHandler class could have used this concept instead of returning a string.
I did make good use of pointers, but only out of necessity.  I struggled with character arrays and ended up figuring out how to 
store the animal's name and tracking number using strings.  My next project I want to use character arrays because after much 
frustration I think I have figured out my problem.  I would instantiate the const char* without setting it to anything, basically pointing
it at nothing and would get compiler errors when trying to then point it at a new char array.  I used a tutoring service as well to 
help me with polymorphism.  It was extremely helpful to get me going with using the Animal pointers to derived classes and was the 
biggest hurdle that I overcame to making the project work as specified by the UML.  I also learned a lot about file input and output through
trial and error.  Overall, I learned a great deal about OOP and C++ basics and I am excited to apply these concepts to future projects and build
upon my foundational skills.

As for my projects design, I hope I made it readable.  I feel like I overcomment, and it looks like it clutters up the code, but the professors
continue to tell me that I am doing well so I will keep doing what I am doing.  As for maintainability and adaptability, there is much work to be done. 
I decided to add an Elephant to my zoo (not one of the original animals) to see how I could implement a new animal type coming to the zoo and 
quickly realized that I designed my program in a way that makes for a lot of unneccessary work to adapt and maintain the software.  I should have used functions
in each derived class to return strings of things that would need to be printed like "Bat" or "Mammal."  That way, I would not have to change the code in other
functions, just point to the function that prints the required string at that point and add the functions to the sub classes.  These are all good
lessons though, and I cannot wait to get my hands on another project, learn from my mistakes, and build a better program next time.
