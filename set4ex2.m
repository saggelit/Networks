clear; clc; clf;
a=load("net2delta.txt");
b=load("net2.txt");
figure(1)
plot(a(:),1:length(a))
title("Κατανομή συνδέσεων στο αρχίκο δίκτυο")
xlabel("Αριθμός συνδέσεων ανά κόμβο - k")
ylabel("Πλήθος εμφάνισης κάθε σύνδεσης")

%% Istogramma anakatanemhmenou diktuou
figure(2)
h=histogram(b)
title("Ιστόγραμμα κατανομής μέσων συνδέσεων k")
xlabel("Αριθμός συνδέσεων ανά κόμβο - k")
ylabel("Πλήθος εμφάνισης κάθε σύνδεσης")
pd=fitdist(b,'Normal')

%% Briskw thn <k>
counts=h.Values/length(a);
c=(h.BinEdges+h.BinWidth/2);
centers=c(1:end-1);
p=0.0;
for i=1:length(counts)
       if p<counts(i)
           p=counts(i);
           imax=i;
       end
end
k=centers(imax)
figure(3)
plot(centers,counts)
title('Συνάρτηση Πυκνότητητας πιθανότητας')
xlabel('Αριθμός συνδέσεων ανά κόμβο - k')
ylabel('P(k)')
text(k,0.01,['<k>=',num2str(k)],'HorizontalAlignment','center')