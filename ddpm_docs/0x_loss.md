# Loss
## What is our exact objective?
Our ultimate objective is:
>$p_\theta$ : distribution of our model's output images 
$\approx$ $p_{data}$ : distribution of the Nature-created flower images

But we could never know the the Nature's distribution ($p_{data}$). The only things we could access are observed data samples $x$. Then we show our data $x$ and ask it "How likely is it that you generated this data $x$?". In this case, the answer from our model is likelihood $p_\theta(x)$ If our model is same as the the Nature, our model must tell us that it assigns a high porbability to this data $x$. Because our data $x$ is from the the Nature. So the higher the likelihood $p_\theta(x)$ is, the more similar our model is to the Nature. That is why we maximize $p_\theta(x)$.

## From Log Likelihood to ELBO
\[
p_\theta(x) = \int p_\theta(x|z)\, p_\theta(z)\,dz
\]
