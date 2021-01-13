#!/bin/python3

import matplotlib.pyplot as plt
import numpy as np
import sys

ref = f'''
    Script for data plotting.
    Usage:
        {__file__} <in_signal> <out_signal> [<out file>]

    <in_signal>:
        Input signal data file.

    <out_signal>:
        Output signal data file.

    <out file>:
        The output plot file name.
'''

if (len(sys.argv) < 3 or sys.argv[1] == "-h" or sys.argv[1] == "--help"):
    print(ref)
    sys.exit(2)

in_sign = sys.argv[1]
out_sign = sys.argv[2]

data_in = np.genfromtxt(in_sign, delimiter=" ", names=["x", "y"])
data_out = np.genfromtxt(out_sign, delimiter=" ", names=["x", "y"])

fig = plt.figure()

in_ax = fig.add_subplot(211)
in_ax.set_title("Input")
in_ax.plot(data_in["x"], data_in["y"])

out_ax = fig.add_subplot(212, sharex=in_ax, sharey=in_ax)
out_ax.set_title("Output")
out_ax.plot(data_out["x"], data_out["y"])

fig.subplots_adjust(hspace=0.5)

out = "plot.png" if len(sys.argv) < 4 else sys.argv[3]
fig.savefig(out)