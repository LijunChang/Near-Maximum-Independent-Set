This repository implements the near-maximum independent set computation algorithms proposed in our SIGMOD 2017 paper. If you are using the code, please cite our paper.
<pre>
Lijun Chang, Wei Li and Wenjie Zhang.
<a href="https://lijunchang.github.io/pdf/2017-mis-sigmod.pdf">Computing A Near-Maximum Independent Set in Linear Time by Reducing-Peeling.</a>
SIGMOD Conference 2017
</pre>

## Compile the code
```sh
$ make clean
$ make
```

## Run the code
Different algorithms can be invoked by executing "mis".
```sh
./mis {alg} {graph_directory}
```
alg is chosen from "greedy, greedy_dynamic, BDOne, BDTwo, LinearTime, NearLinear"

For example,
```sh
./mis LinearTime datasets/CA-GrQc
```

## Data format
Each graph is represented by two binary files, b_adj.bin and b_degree.bin (e.g. datasets/CA-GrQc/b_adj.bin and datasets/CA-GrQc/b_degree.bin). More details of the data format can be found in [https://lijunchang.github.io/Cohesive_subgraph_book/datasets](https://lijunchang.github.io/Cohesive_subgraph_book/datasets)
