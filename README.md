PLN Processing Program
======================

Loads a saved Piecewise Linear Network (PLN) network and processes a new data vector through it for testing.

There is version that loads the PLN network from a weights file stored on the disk. This is the recommended method. See pln_processing.c. To compile:
	gcc pln_processing.c -o pln_processing
The example assumes the PLN weights files for the two networks used are in the data folder.

There is another version that loads PLN weights from structures loaded with static data. This requires that the structure elements be updated in the source file on every update in weights. Although this method is not recommended, it can be useful in cases where reading a weights file from the disk is not possible. See pln_processing_nofile.c. To compile:
	gcc pln_processing_nofile.c -o pln_processing_nofile
The example assumes the PLN weights files for the two networks used are stored in the C files plnX_weights.c. These are included into pln_processing_nofile.c.

