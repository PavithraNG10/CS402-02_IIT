import pandas as pd
import matplotlib.pyplot as plt

# Read the trace file into a DataFrame for cc1.din
df_cc1 = pd.read_csv('cc1.din.txt', sep=' ', names=['operation', 'address'], dtype={'operation': int, 'address': str})

# Filter and convert hexadecimal addresses to decimal for cc1.din
filtered_df_cc1 = df_cc1[df_cc1['operation'].isin([0, 1, 2])]
filtered_df_cc1['address'] = filtered_df_cc1['address'].apply(lambda x: int(x, 16))

# Read the trace file into a DataFrame for spice.din
df_spice = pd.read_csv('spice.din.txt', sep=' ', names=['operation', 'address'], dtype={'operation': int, 'address': str})

# Filter and convert hexadecimal addresses to decimal for spice.din
filtered_df_spice = df_spice[df_spice['operation'].isin([0, 1, 2])]
filtered_df_spice['address'] = filtered_df_spice['address'].apply(lambda x: int(x, 16))

# Define colors for each operation
colors = ['red', 'green', 'blue']

# Create separate subplots for cc1.din
fig_cc1, axes_cc1 = plt.subplots(3, 1, figsize=(8, 12))
print("Histogram for CC1.din")
for i, (operation, color) in enumerate(zip([0, 1, 2], colors)):
    ax = axes_cc1[i]
    ax.hist(filtered_df_cc1[filtered_df_cc1['operation'] == operation]['address'], bins=100, color=color, alpha=0.5)
    ax.set_xlabel("Address (Decimal)")
    ax.set_ylabel("Occurrences")
    ax.set_title(f'Address Distribution for Operation {operation}')

plt.tight_layout()
plt.savefig('cc1_histogram.png')
plt.show()

# Create separate subplots for spice.din
fig_spice, axes_spice = plt.subplots(3, 1, figsize=(8, 12))
print("Histogram for Spice.din")
for i, (operation, color) in enumerate(zip([0, 1, 2], colors)):
    ax = axes_spice[i]
    ax.hist(filtered_df_spice[filtered_df_spice['operation'] == operation]['address'], bins=100, color=color, alpha=0.5)
    ax.set_xlabel("Address (Decimal)")
    ax.set_ylabel("Occurrences")
    ax.set_title(f'Address Distribution for Operation {operation}')

plt.tight_layout()
plt.savefig('spice_histogram.png')
plt.show()

# Calculate the frequency of writes, reads, and instruction fetch for cc1.din
writes_cc1 = (filtered_df_cc1['operation'] == 1).sum()
reads_cc1 = (filtered_df_cc1['operation'] == 0).sum()

# Calculate the frequency of writes, reads, and instruction fetch for spice.din
writes_spice = (filtered_df_spice['operation'] == 1).sum()
reads_spice = (filtered_df_spice['operation'] == 0).sum()

print("Frequency of Writes for CC1.din:", writes_cc1)
print("Frequency of Reads for CC1.din:", reads_cc1)
print("Frequency of Writes for Spice.din:", writes_spice)
print("Frequency of Reads for Spice.din:", reads_spice)

print("Total Frequency of Reads:", reads_cc1+reads_spice)
print("Total Frequency of Writes:", writes_cc1+writes_spice)

