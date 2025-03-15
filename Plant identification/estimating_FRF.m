%% Pre
clear all
clc; clf;
addpath('Measurements')
%% Load data
Fs = 4000;
open_loop = load('Measurements\measurement_open_loop_14_of_march_1.mat').measurements_open_loop;
closed_loop = load('measurement_closed_loop_14_of_march_2.mat').measurement_closed_loop;

y_o = open_loop(:,1);
u_o = open_loop(:,2);

d_c = closed_loop(:,1);
u_c = closed_loop(:,2);
e_c = closed_loop(:,3);
%% estimate open loop for one frame

frame_length_open = 16000;
[H_hat, f_hat_open] = tfestimate(u_o, y_o, hann(frame_length_open),frame_length_open/2,frame_length_open, Fs);
dataBode(H_hat, f_hat_open)

%% estimate open loop for many frame lengths

frame_length_options = [32000, 16000]; % [1000, 4000, 16000, 64000, 128000]
for i = 1:length(frame_length_options)
    frame_i = frame_length_options(i);
    [H_i, f_i] = tfestimate(u_o, y_o, hann(frame_i),frame_i/2,frame_i, Fs);
    semilogx(f_i,db(H_i));
%     [C_uy, f_i] = mscohere(u_o, y_o, hann(frame_i),frame_i/2,frame_i, Fs);
%     semilogx(f_i,C_uy);
    hold on
end
hold off
legend(num2str(frame_length_options'))

% Chosing frame length
% 16000 is more smooth than 4000. 4000 is noisy.
% For 16k, 32k, and 48k the resulting function, and the noise at high
% frequencies is hard to distinguish. the function in generals are
% basically identical, but the noise at high frequencies has barely smaller
% variation for 16k.
% Coherence for 48k is suspiciously close to 1 for most frequencies. 


%% DataBode
function dataBode(H,f)
    figure;
    subplot(2,1,1);
    semilogx(f,db(H))
    ylabel('|H| (db)')
    subplot(2,1,2);
    semilogx(f,angle(H)/pi*180)
    ylabel('\angle H (\degree)')
    xlabel('f (Hz)')
end

