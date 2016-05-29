% % Simple three layer neural network
% clear;
% %---------------------------------------
% 
Read();

% w ten sposob czytac kazdy wiersz
% first = reshape(image_matrix(1,:),8,16)'


neuron_count = [128,8,26];
RandomWeightsGeneration(neuron_count);
% Process(neuron_count);

shorter_data_image = image_matrix(1:100,:);
shorter_data_letters = letters(1:100,:);
