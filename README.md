# cs-330-computational-graphics-and-visualization

This repository contains the implementation of a 3D scene developed using C++ and OpenGL. The project focuses on creating low-polygon 3D objects, applying textures, and setting up lighting within a virtual environment. The final project replicates a 2D image in 3D using basic geometric shapes, with functionality for camera navigation and scene interaction. The code is modular and includes a design decisions document discussing the approach and functionality implemented throughout the project.
<br><br>The work in this repository was completed as part of SNHU's CS-330 Computer Graphics and Visualizations course.

## <br>3D Scene Screenshot:
![](3d%20scene%20screenshot.png)

## <br>3D Scene Source Code:
- **[MainCode.cpp](3d%20scene%20source%20code/MainCode.cpp)**
<br>Initializes the GLFW and GLEW libraries, sets up essential components like scene, view, and shader managers, and runs the main rendering loop for a 3D graphical application using OpenGL.<br>

- **[MyObjects.cpp](3d%20scene%20source%20code/MyObjects.cpp)**
<br>Handles drawing and positioning various objects in a 3D scene using a SceneManager for transformations and rendering.<br>

- **[SceneManager.cpp](3d%20scene%20source%20code/SceneManager.cpp)**
<br>Handles loading, binding, and applying textures, materials, transformations, and shader configurations for rendering 3D objects with OpenGL.<br>

- **[ViewManager.cpp](3d%20scene%20source%20code/ViewManager.cpp)**
<br>Manages the 3D viewport's camera controls, including movement, zoom, and projection types, while handling mouse and keyboard input events for interactive scene navigation and rendering.<br>

## <br>Design Decisions Document:
- **[design decisions.pdf](design%20decisions.pdf)**
<br>Reflects on the design process and implementation of a 3D scene based on a family photo, detailing the creation of complex objects, camera controls, and code modularization to achieve a realistic and interactive virtual environment.<br>

## <br>Additional Insights:
### How do I approach designing software?
#### What new design skills has your work on the project helped you to craft?
One new design skill I learned by completing the project is perspective analysis. I was required to analyze my reference 2D image for depth, perspective, and spatial relationships to translate its objects into 3D space. The project taught me how to simulate real-world lighting and shadows using the Phong reflection model. This included understanding ambient, diffuse, and specular lighting, which helped me create a more realistic and visually appealing 3D scene. I also developed skills in applying textures by learning about UV mapping, adjusting UV scale, and ensuring textures aligned properly with the geometry of my models, enhancing the overall quality of the scene.
#### What design process did you follow for your project work?
I followed a structured design process for my project. I began by setting up the foundational elements of the scene, such as the ground, sky, and water planes. Next, I added simple objects to establish the layout before incorporating more complex ones. Careful planning was crucial, as rendering objects in OpenGL required significant time.
#### How could tactics from your design approach be applied in future work?
Tactics from my design approach, such as breaking a problem into smaller components, starting with foundational elements, and prioritizing careful planning, can be applied to all areas of software engineering. For example, in backend programming, this approach could involve structuring databases or APIs step by step, beginning with basic functionality before adding more complex features. These principles ensure efficiency and scalability in future projects.
### How do I approach developing programs?
#### What new development strategies did you use while working on your 3D scene?
I focused on leveraging reusable code by creating functions for repetitive tasks, such as generating objects and applying transformations. This saved time and made my codebase more modular and easier to debug.
#### How did iteration factor into your development?
Iteration played a key role in my development process. After each change, I frequently tested the scene, ensuring each new element worked as expected before adding more complexity. This iterative approach allowed me to catch issues early, refine my design, and optimize performance incrementally. By revisiting and adjusting earlier steps as I progressed, I improved the overall quality of the 3D scene.
#### How has your approach to developing code evolved throughout the milestones, which led you to the project’s completion?
Early on, I focused on basic meshes and simple elements, but as we moved through the milestones, I began incorporating more complex meshes to strive for greater realism. I also started modularizing the program, creating custom functions to handle specific tasks and establishing a clear separation of concerns between classes. This helped improve organization, efficiency, and maintainability, leading to a more polished and functional final scene.
### How can computer science help me in reaching my goals?
#### How do computational graphics and visualizations give you new knowledge and skills that can be applied in your future educational pathway?
Working with computational graphics and visualizations has taught me valuable skills like modularity, optimization, and efficient data visualization. These skills will be useful in UI/UX design, helping me create intuitive interfaces, and in software development, where performance and clear data presentation are key.
#### How do computational graphics and visualizations give you new knowledge and skills that can be applied in your future professional pathway?
Computational graphics and visualizations have strengthened my problem-solving and optimization skills, which are essential for building efficient, high-performance systems. These skills will be valuable in my future backend work, where managing resources and ensuring scalability and performance are key.
