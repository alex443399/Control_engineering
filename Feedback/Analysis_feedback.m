% load measurements for error Kff yes ff
load('Controllers\measurements\measurement_c4.mat');
load('Controllers\measurements\measurement_c5.mat');
%%
[e2_raw, cvel_2] = get_relevant_error_data(measure_control_FF_yesFF,1);
[e4_raw, cvel_4] = get_relevant_error_data(measurements_reference_c4,1);
[e5_raw, cvel_5] = get_relevant_error_data(measurements_reference_c5,1);
%%
plot((1:length(e2_raw))/4000,...
    e2_raw*1000)
hold on
plot((1:length(e4_raw))/4000,...
    e4_raw*1000)
hold on
plot((1:length(e5_raw))/4000, ...
        e5_raw*1000)
hold on
fill([0 845 845 0]/4000, [-0.1 -0.1 0.15 0.15]*1000, 235/255*[1 1 1],'LineStyle',"none")
hold on
fill([22729 24416 24416 22729]/4000, [-0.1 -0.1 0.15 0.15]*1000, 235/255*[1 1 1],'LineStyle',"none")
hold on
fill([46300 47143 47143 46300]/4000, [-0.1 -0.1 0.15 0.15]*1000, 235/255*[1 1 1],'LineStyle',"none")
hold off
ylim([-.1,.15]*1000)
legend('K_{ff}', 'K_{res}', 'K_{dist}', 'velocity not constant')
xlabel('Time (s)')
ylabel('Error (mrad)')
title('Time domain error profile for different controllers')
%% Frequency analysis

FE2 = get_first_stroke(e2_raw, cvel_2);
FE4 = get_first_stroke(e4_raw, cvel_4);
FE5 = get_first_stroke(e5_raw, cvel_5);
%%
pwelch([FE2 FE4 FE5],hann(8000),4000,8000,4000);
%%
[psd, freqs]=pwelch([FE2 FE4 FE5],hann(8000),4000,8000,4000);

semilogx(freqs, db(psd))
xlabel('f (Hz)')
ylabel('Power (db)')
title('PSD of error comparison (with FF)')
legend("K_{ff}","K_{res}","K_{dist}")


%%
e2 = e2_raw(cvel_2);
rms(e2)*1000
max(e2)*1000
%%
e4 = e4_raw(cvel_4);
rms(e4)*1000
max(e4)*1000
%%
e5 = e5_raw(cvel_5);
rms(e5)*1000
max(e5)*1000
%% Analyzing steady state
tf_controller_5 = load('Controllers\controller_5.mat').shapeit_data.C_tf;
bodemag(tf_controller_5)
%%

%% Functions
function err = get_first_stroke(err, vconst)
    e_desired = err(vconst);
    N = length(e_desired);
    N_over_2 = floor(N/2);
    err = e_desired(1:N_over_2);
end

function [error, constant_velocity] = get_relevant_error_data(measurement, period_choice)
    % measurement has channels: error, acc, vel
    % period_choice can be 1,2,3,4

    candidates_for_starter_index = find(measurement(:,3)==0);

    sample_initial = candidates_for_starter_index(period_choice);
    sample_final = candidates_for_starter_index(period_choice+1)-1;
    error = measurement(sample_initial:sample_final,1);
    acc = measurement(sample_initial:sample_final,2);
    velocity = measurement(sample_initial:sample_final,3);
    
    constant_velocity = acc==0 & velocity ~= 0;
end