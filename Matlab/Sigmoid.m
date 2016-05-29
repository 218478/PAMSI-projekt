function output = Sigmoid( input )
%SIGMOID Summary of this function goes here
%   Detailed explanation goes here
    beta = 1.0;
    output = 1/(1+exp(beta*(-input)));
end

