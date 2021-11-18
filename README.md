# USPS-Data-Analysis
Performed data analysis on two sets of experimental data used for tracking USPS shipments in order to find the data structure that yields the most ideal balance in run-time performance.

## Analysis
When generating the data needed to plot a graph showing average search and insert times, 
we designed functions within the classes that performed the increments of adding 100 new pieces of data from the dataset and searching 100 times for values within the expected range of random number values that can be searched. 
This greatly helped keep the actual experiment concise and easy to debug. 
Overall the results of our project reveal a lot about the real world time to complete that occur with different types of data structures.

### Linked Lists
It is plainly obvious that Linked List is the worst choice for a data structure in terms of processing times and overall efficiency. Between two different data sets, it managed to keep consistency but was consistently the slowest overall in terms of average completion time and overall time to complete. It’s simply because of the structure itself; sure traversing the first data point takes no time at all, but having to make your way to the 40000th data point from the first is too efficient for even more than 100 data points let alone hundreds of thousands per hour.

### Binary Search Trees
Binary search trees were a much better improvement upon last place Linked Lists. They also managed to keep consistent average time behavior through both data sets and were 70-80% more efficient overall. Their overall performance was worlds better, and that’s also due to their structure. The insert and search functions perform almost identical traversals in order to reach their destinations, a traversal method that is exponentially more efficient than a linked list. That’s why insert and traversal times are similar, and why overall efficiency benefits greatly as a result.

### Hash Tables
Hash tables overall took very little time and were comparable to the times for BST insert and search. Outside of some anomalies in the chained link list data, it overall showed sub 250ns average times mostly through the experiment. Out of the three methods of insert/search, our data shows that linear probing was the most consistent and lowest time to complete overall with mostly sub 200nn times, the fastest of all other times. The use of hash functions overall was the major factor in making this data structure the most efficient, because instead of having to do any traversing that the linked list and even the BST have to do, lists can be accessed simply through the use of the table and the hash function position indexes. That makes data insert and search significantly more consistent with the same step consistency.

## Conclusion
Overall of the three data structures, we recommend the use of the hash table data structure to be the foundation for its mail tracking software. It provides the fastest and most efficient method of traversal, outperforming its competition with marginal to significant gains in all areas.

## Snaps

<img src="screenshots/Screen Shot 2021-11-18 at 2.58.37 PM.png" height="600px" width="950pxpx">
<img src="screenshots/Screen Shot 2021-11-18 at 2.59.04 PM.png" height="350px" width="950pxpx">
<img src="screenshots/Screen Shot 2021-11-18 at 2.59.27 PM.png" height="350px" width="950pxpx">
<img src="screenshots/Screen Shot 2021-11-18 at 2.59.45 PM.png" height="350px" width="950pxpx">
<img src="screenshots/Screen Shot 2021-11-18 at 3.00.13 PM.png" height="350px" width="950pxpx">
<img src="screenshots/Screen Shot 2021-11-18 at 3.00.29 PM.png" height="350px" width="950pxpx">
