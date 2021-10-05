'''
Author: LeBronLiHD
Date: 2021-10-05 21:54:00
LastEditTime: 2021-10-05 22:06:31
LastEditors: Please set LastEditors
Description: Plot curves of different time complexity
FilePath: \1_Project_Hard\plot_curve.py
'''

import matplotlib.pyplot as plt
import os


def main(save_path):
    print("Plot curves of different time complexity...")
    X = [5, 10, 30, 50, 80, 100]
    Y_1 = [0.00084, 0.00207, 0.08156, 1.4591, 23.9372, 75.608]
    Y_2 = [0.00078, 0.0012, 0.00286, 0.0153,  0.09115,  0.2413]
    Y_3 = [0.00071, 0.00084, 0.00157, 0.00241, 0.00381, 0.00557]
    # plot version one
    plt.figure()
    plt.plot(X, Y_1, color="red")
    plt.xlabel("Value of N")
    plt.ylabel("Time Cost (s)")
    plt.title("O(N^6)")
    plt.savefig(os.path.join(save_path, "version_one.png"))
    plt.show()
    # plot version two
    plt.figure()
    plt.plot(X, Y_2, color="green")
    plt.xlabel("Value of N")
    plt.ylabel("Time Cost (s)")
    plt.title("O(N^4)")
    plt.savefig(os.path.join(save_path, "version_two.png"))
    plt.show()
    # plot version three
    plt.figure()
    plt.plot(X, Y_3, color="blue")
    plt.xlabel("Value of N")
    plt.ylabel("Time Cost (s)")
    plt.title("O(N^3)")
    plt.savefig(os.path.join(save_path, "version_three.png"))
    plt.show()
    # plot together
    plt.figure()
    plt.plot(X[0:len(X) - 3], Y_1[0:len(X) - 3], color="red")
    plt.plot(X[0:len(X) - 3], Y_2[0:len(X) - 3], color="green")
    plt.plot(X[0:len(X) - 3], Y_3[0:len(X) - 3], color="blue")
    plt.xlabel("Value of N")
    plt.ylabel("Time Cost (s)")
    plt.title("All Versions")
    plt.savefig(os.path.join(save_path, "version_all.png"))
    plt.show()
    print("Plot done!")


if __name__ == "__main__":
    path = "./curves"
    main(path)
