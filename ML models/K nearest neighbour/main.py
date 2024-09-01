import pandas as pd

# Load the Iris dataset'  # Replace with your file path
iris_data = pd.read_csv("Iris.csv")

def split_dataset(species_name, file_prefix):
    # Filter the dataset for the specified species
    species_data = iris_data[iris_data['Species'] == species_name]
    
    # Sample 70% of the species entries for training
    train_species = species_data.sample(frac=0.7, random_state=1)
    
    # Get the remaining 30% for testing
    test_species = species_data.drop(train_species.index)
    
    # Save the training set to a CSV file
    train_file = f'{file_prefix}_train.csv'
    train_species.to_csv(train_file, index=False)
    
    # Save the testing set to a CSV file
    test_file = f'{file_prefix}_test.csv'
    test_species.to_csv(test_file, index=False)
    
    return train_file, test_file

# Split the dataset for Iris-setosa
train_setosa_file, test_setosa_file = split_dataset('Iris-setosa', 'Iris_setosa')
print(f'Iris-setosa training set: {train_setosa_file}')
print(f'Iris-setosa testing set: {test_setosa_file}')

# Split the dataset for Iris-virginica
train_virginica_file, test_virginica_file = split_dataset('Iris-virginica', 'Iris_virginica')
print(f'Iris-virginica training set: {train_virginica_file}')
print(f'Iris-virginica testing set: {test_virginica_file}')
