import java.util.LinkedHashSet;
import java.util.Scanner;

public class PageScheduling {

    public static void main(String[] args) {

        // User input
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); // Cache Size
        int m = sc.nextInt(); // Page Request Times

        PageManager pageManager = new PageScheduling().new PageManager(n);

        for (int i = 0; i < m; i++) {
            pageManager.pageIn(sc.nextInt());
        }

        sc.close();

        pageManager.getAnswer();

    }

    public class PageManager {

        private int output = 0;
        private int cacheMaxSize;
        private int count;
        private LinkedHashSet<Integer> pages;

        public PageManager(int cacheMaxSize) {
            this.cacheMaxSize = cacheMaxSize;
            this.pages = new LinkedHashSet<>();
        }

        public boolean isFull() {
            return this.count == this.cacheMaxSize;
        }

        public void pageIn(int pageNum) {

            if (!pages.contains(pageNum)) {
                // pages do not include specifc pageNum
                output++;

                if (this.isFull()) {
                    // remove first one
                    this.pages.remove(this.pages.iterator().next());
                    // add one and don't change the count

                } else {
                    pages.add(pageNum);
                }
            } else {
                // nothing to do because pages contains pageNum
            }
        }

        public void getAnswer() {
            System.out.println(this.output);
        }

    }
}