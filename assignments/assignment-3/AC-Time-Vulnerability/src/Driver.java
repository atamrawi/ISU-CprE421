
import list.ShapesCatalog;
import list.TimeLimitExceededException;
import shapes.Circle;
import shapes.Shape;
import shapes.ShapeUtils;

/**
 * The main driver class for your experiements.
 */
public class Driver {

	/**
	 * The number of {@link ShapesCatalog}s to generate.
	 */
	private final static int SHAPES_CATALOG_COUNT = 100;
	
	/**
	 * The number of geometric {@link Shape}s within each {@link ShapesCatalog}.
	 */
	private final static int SHAPES_CATALOG_LENGTH = 6;
	
	/**
	 * The main driver for the shape catalog project.
	 * 
	 * @param args The program currently accepts no arguments.
	 */
	public static void main(String[] args) {
		baseExperiement();
	}
	
	public static void baseExperiement() {
		int rewardsCount = 0; // store the number of rewards gained.
		
		for(int catalogIndex = 0; catalogIndex < SHAPES_CATALOG_COUNT; catalogIndex++) {
			
			Shape [] shapes = new Shape[SHAPES_CATALOG_LENGTH]; // Creates a shapes array of size SHAPES_CATALOUGE_LENGTH.
			for(int i = 0; i < SHAPES_CATALOG_LENGTH; i++) {
				if(i == 3) {
					//#############################################
					// You are only allowed to control the if condition and the shapes to add within this code block.
					shapes[i] = new Circle();
					//#############################################
				} else {
					Shape shape = ShapeUtils.createRandomShape(); // creates a random shape.
					shapes[i] = shape;
				}
			}
			ShapesCatalog catalog = new ShapesCatalog(shapes); // constructs a new shapes catalog.
			try {
				catalog.getStats(); 
				//System.out.println(catalog.getStats()); print the stats
			} catch (TimeLimitExceededException e) {
				rewardsCount++; // We have gained a new reward; increment the rewardsCount.
			}
			catalog.destroy(); // destroy the shapes catalog.
		}
		System.out.println("(Base Experiment) You have gained [" + rewardsCount + "] rewards out of [" + SHAPES_CATALOG_COUNT + "] rewards!");
	}
	
}
