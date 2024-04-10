**# Push Swap**

**Introduction**

This project, created as part of the 42 Paris curriculum, tackles the challenge of efficiently sorting a list of numbers. Leveraging two stacks and a restricted set of operations, the project includes:

* **push_swap:** Produces the sorting instructions.
* **checker:** Confirms the instructions successfully sort the list.

**Building**

To build the project from source code, simply run the following command in your terminal:

```bash
make
```

This command will utilize the Makefile to compile and link the necessary source files.

**Testing**

Use the following command to test the project:

```bash
ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG 
```

**Visualization**

Gain a visual understanding of the sorting process by running the `checker` with the `-v` flag. This activates the built-in visualizer.

![Visualization](files/visualization.gif) 
