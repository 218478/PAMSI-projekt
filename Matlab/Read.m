function [ output_args ] = Read( input_args )
%READ Summary of this function goes here
%   Detailed explanation goes here

fileID = fopen('letter.data');

data = reshape(textread('letter.data','%s'),134,52152)';
letters = data(:,2);
image_matrix = data(:,7:134);

assignin('base','letters',letters);
assignin('base','image_matrix',image_matrix);

end

