% % Simple three layer neural network
% clear;
% 
% fileID = fopen('letter.data');
% 
% each_cell = textread('letter.names','%s','delimiter',' ');
% 
% data = reshape(textread('letter.data','%s'),134,52152)';
% 
% letters = data(:,2);
% image_matrix = data(:,7:134);


% w ten sposob czytac kazdy wiersz
% first = reshape(image_matrix(1,:),8,16)'

layer_count = 3;

Sigmoid(0);

for i=1:layer_count
    
end

