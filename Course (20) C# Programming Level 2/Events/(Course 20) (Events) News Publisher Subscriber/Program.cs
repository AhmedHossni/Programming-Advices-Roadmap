using System;
using System.Reflection;

namespace _Course_20___Events__News_Publisher_Subscriber
{
    public class NewsArticle
    {
        public NewsArticle(string title, string content)
        {
            Title = title;
            Content = content;
        }

        public string Title { get;}
        public string Content { get;}
    }

    public class NewsPublisher
    {
        public event EventHandler<NewsArticle> NewNewsArticle;

        public void PublishNews(string title, string content)
        {
            NewsArticle newsArticle = new NewsArticle(title, content);

            OnNewNewsPublished(newsArticle);
        }

        protected virtual void OnNewNewsPublished (NewsArticle newsArticle)
        {
            NewNewsArticle?.Invoke(this ,newsArticle);
        }
    }

    public class NewsSubscriber
    {
        public NewsSubscriber(string name)
        {
            Name = name;
        }

        public string Name { get; }

        public void Subscribe (NewsPublisher newsPublisher)
        {
            newsPublisher.NewNewsArticle += OnNewsPublisher_NewNewsArticle;
        }

        public void UnSubscribe (NewsPublisher newsPublisher)
        {
            newsPublisher.NewNewsArticle -= OnNewsPublisher_NewNewsArticle;
        }

        protected virtual void OnNewsPublisher_NewNewsArticle(object sender, NewsArticle e)
        {
            Console.WriteLine($"Subscriber Name : {Name}");
            Console.WriteLine($"************************");
            Console.WriteLine($"\t\t{e.Title}");
            Console.WriteLine($"\n {e.Content}");
        }
    }


    internal class Program
    {
        static void Main(string[] args)
        {
            // I don't understand the example very well but, i make it anyway.

            NewsSubscriber newsSubscriber = new NewsSubscriber("Hamada");

            NewsPublisher newsPublisher = new NewsPublisher();

            string title = "Article About Wars";

            string content = "Wars is not good for humans and it makes a lot of damage.";

            newsSubscriber.Subscribe(newsPublisher);

            newsPublisher.PublishNews(title, content);

        }
    }
}
